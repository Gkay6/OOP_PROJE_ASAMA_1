#include "Mapper.h"

Mapper::Mapper(MAP &map, RobotController* controller, LidarSensor lidar)
	:map(map), controller(controller), lidar(lidar)
{
}

void Mapper::updateMap()
{
	Pose current_location = controller->getPose();
	//current_location.getX()		x0
	//current_location.getY()		y0
	//current_location.getTh()		alpha
	//667 sayisini nerden alacagini bul 
	for (int i = 0; i < 667; i++)
	{
		Point temp_point;
		temp_point.setX
		(
			current_location.getX() + lidar[i] * (std::cos((current_location.getTh() + lidar.getAngle(i)) * (M_PI / 180.0)))
			// x1 = x0 + d * cos(alpha + beta)
		);

		temp_point.setY
		(
			current_location.getY() + lidar[i] * (std::sin((current_location.getTh() + lidar.getAngle(i)) * (M_PI / 180.0)))
			// y1 = y0 + d * sin(alpha + beta)
		);
		map.insertPoint(temp_point);
	}
}

bool Mapper::recordMap()
{
	return false;
}

void Mapper::showMap()
{
	map.showMap();
}

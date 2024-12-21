#include "Mapper.h"

#define SCALE 4
Mapper::Mapper(RobotController* controller, LidarSensor& lidar)
	:map((int)(16 * SCALE), (int)(16 * SCALE), (int)(-7.5 * SCALE), (int)(-7.5 * SCALE)), controller(controller), lidar(lidar)
{
}

void Mapper::updateMap()
{
	Pose current_location = controller->getPose();
	lidar.update();
	//current_location.getX()		x0
	//current_location.getY()		y0
	//current_location.getTh()		alpha (radyan)
	std::cout << current_location.getTh() << std::endl;
	for (int i = 0; i < lidar.getRangeNumber(); i++)
	{
		const double d = lidar[i];
		if (d != INFINITE && -d != INFINITE)
		{
			Point temp_point;
			//std::cout << i << " " << current_location.getX() << " + " << lidar[i] << " * cos(" << (current_location.getTh() + lidar.getAngle(i)) * (M_PI / 180.0) << ")" << std::endl;
			temp_point.setX
			(
				SCALE * (current_location.getX() + d * (std::cos(current_location.getTh() + lidar.getAngle(i) * (M_PI / 180.0))))
				// x1 = x0 + d * cos(alpha + beta)
			);

			temp_point.setY
			(
				SCALE * (current_location.getY() + d * (std::sin(current_location.getTh() + lidar.getAngle(i) * (M_PI / 180.0))))
				// y1 = y0 + d * sin(alpha + beta)
			);
			//std::cout << i << "-> " << (float)temp_point.getX() << ", " << (float)temp_point.getY() << std::endl;
			map.insertPoint(temp_point);
		}		
	}
	current_location = controller->getPose();
	std::cout << current_location.getTh() << std::endl;
}

bool Mapper::recordMap()
{
	Record robotino_record;
	robotino_record.setFileName(std::string("Mapper.txt"));
	if (robotino_record.openFile())
	{
		for (int i = map.getNumberY() - 1 - (int)(7.5 * SCALE); i >= -(int)(7.5 * SCALE); i--)
		{
			std::string temp_line;
			for (int j = -(int)(7.5 * SCALE); j < map.getNumberX() - (int)(7.5 * SCALE); j++)
			{
				int temp = map.getGrid(j, i);
				if (temp == 0 || temp == -1)
				{
					temp_line.push_back('.');
				}
				else
				{
					temp_line.push_back('x');
				}
			}
			temp_line.push_back('\n');

			robotino_record << temp_line;
		}
		return true;
	}
	std::cerr << "Error with Mapper::recordMap  Record::openFile() " << std::endl;
	return false;
}

void Mapper::showMap()
{
	map.showMap();
}

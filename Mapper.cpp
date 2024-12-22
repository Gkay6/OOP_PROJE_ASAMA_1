/*!
 * \file Mapper.h
 * \author Utku Buðra Namkazan
 * \date 22.12.2024
 * \brief Implementation file for the Mapper class,
 * \which gets data from lidar sensors from LidarSensor class,
 * \gets data from pose information from RobotController class,
 * \stores the data at a map from MAP class,
 * \records the data to a file using Record class
 */
#include "Mapper.h"

#define SCALE 4//!< Scale factor for converting real-world coordinates to grid coordinates.

/*! \brief Mapper constructor implementation. */
Mapper::Mapper(RobotController* controller, LidarSensor& lidar)
	:map((int)(16 * SCALE), (int)(16 * SCALE), (int)(-7.5 * SCALE), (int)(-7.5 * SCALE)), controller(controller), lidar(lidar)
{
}

/*! \brief Updates the map based on the robot's current pose and lidar sensor data. */
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
			map.insertPoint(temp_point);
		}		
	}
	current_location = controller->getPose();
	std::cout << current_location.getTh() << std::endl;
}

/*! \brief Records the current map to a file.
 *  \return True if the map was successfully recorded, false otherwise.
 */
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

/*! \brief Displays the current map on the console. */
void Mapper::showMap()
{
	map.showMap();
}

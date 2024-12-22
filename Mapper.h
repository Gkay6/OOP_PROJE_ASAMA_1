#ifndef MAPPER_H
#define MAPPER_H
#ifndef M_PI
#define M_PI 3.14159265358979323846 //!< Define PI if not already defined.
#endif

#include "LidarSensor.h"
#include "RobotController.h"
#include "MAP.h"
#include "Record.h"

/*! \class Mapper
 *  \brief A class that manages mapping using a lidar sensor and robot controller.
 */
class Mapper
{
private:
	RobotController* controller; //!< Pointer to the RobotController instance.
	LidarSensor& lidar; //!< Reference to the LidarSensor instance.
	MAP map; //!< The map object to store and manage grid-based map data.
public:
	
	/*! \brief Constructor that initializes the Mapper with a controller and lidar sensor.
	 *  \param controller Pointer to an instance of RobotController.
	 *  \param lidar Reference to an instance of LidarSensor.
	 */
	Mapper(RobotController* controller, LidarSensor& lidar);

	/*! \brief Updates the map using the current pose and lidar data. */
	void updateMap();

	/*! \brief Records the map to a file.
	 *  \return True if the map was successfully recorded, false otherwise.
	 */
	bool recordMap();

	/*! \brief Displays the map on the console. */
	void showMap();
};
#endif

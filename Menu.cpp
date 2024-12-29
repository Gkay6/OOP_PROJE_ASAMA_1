/**
 * @file   Menu.cpp
 * @author Gokay Taspinar
 * @date   29.12.2024
 * @brief  Implementation of the Menu class methods
 */

#include "Menu.h"
#include "FestoRobotInterface.h"

 /*!
  * Initializes robot api but also the robot controller for the connectRobot() function
  */
Menu::Menu(FestoRobotAPI* robotAPI) :
	robotAPI(robotAPI), is_robot_connected(false){

	FestoRobotInterface* robot_interface = new FestoRobotInterface(robotAPI);
	std::list<SensorInterface*> sensorList;
	robot_controller = new RobotController(sensorList, robot_interface,"Name",1234);

	Main_Menu();
}


/*!
 * Creates objects which are neccessary for the robot like sensors and controllers
 */
void Menu::create_objects() {

	// Creates the objects once
	// However, we still cant connect after a disconnect beacuse FestoRobotAPI deosnt work
	// But, this code piece is probably needed for other working APIs

	static bool is_objects_created = false;
	
	if (!is_objects_created) {
		ir_sensor = new IRSensor(robotAPI);
		lidar_sensor = new LidarSensor(robotAPI);
		safe_navigation = new SafeNavigation(robot_controller, ir_sensor);
		mapper = new Mapper(robot_controller, lidar_sensor);

		robot_controller->addSensor(ir_sensor);
		robot_controller->addSensor(lidar_sensor);
		is_objects_created = true;
	}
}


/*!
 * Menu starts from here, users can open Connection, Motion and Sensor menus
 */
void Menu::Main_Menu() {
	std::string menu_text = "Main Menu\n1. Connection\n2. Motion\n3. Sensor\n4. Quit\n";

	bool loop = true;
	while (loop) {

		int choice = 0;
		std::cout << menu_text << "Choose one: ";
		std::cin >> choice;
		std::cout << "\n";

		switch (choice) {
		case 1:
			Connection_Menu();
			break;
		case 2:
			if (!is_robot_connected) {
				std::cout << "Can't use motion menu before connecting to the robot\n\n";
				break;
			}
			Motion_Menu();
			break;
		case 3:
			if (!is_robot_connected) {
				std::cout << "Can't use sensor menu before connecting to the robot\n\n";
				break;
			}
			Sensor_Menu();
			break;
		case 4:
			std::cout << "Quit\n";
			loop = false;
			break;
		default:
			std::cout << "Invalid option, enter again\n\n";
		}
	}
}


/*!
 * Connection menu, users can connect or disconnect to the robot
 */
void Menu::Connection_Menu() {
	std::string menu_text = "Connection Menu\n1. Connect Robot\n2. Disconnect Robot\n"
		"3. Open Access\n4. Close Access\n5. Back\n";

	bool loop = true;
	while (loop) {

		int choice = 0;
		std::cout << menu_text << "Choose one: ";
		std::cin >> choice;
		std::cout << "\n";
		int access_code;

		switch (choice) {
		case 1:
			std::cout << "<Connect>\n";

			if (robot_controller->connectRobot()) {
				is_robot_connected = true;
				create_objects();
			}
			break;
		case 2:
			std::cout << "<Disconnect>\n";
			if (robot_controller->disconnectRobot()) {
				is_robot_connected = false;
			}
			break;
		case 3:
			std::cout << "Enter password to open access: ";
			std::cin >> access_code;

			if (robot_controller->openAccess(access_code)) {
				std::cout << "Succesfully opened the access\n";
			}
			break;
		case 4:
			std::cout << "Enter password to close access: ";
			std::cin >> access_code;

			if (robot_controller->closeAccess(access_code)) {
				std::cout << "Succesfully closed the access\n";
			}
			break;
		case 5:
			std::cout << "Back\n";
			loop = false;
			break;
		default:
			std::cout << "Invalid option, enter again\n\n";
		}
	}

	// Back, returns to the main menu
}


/*!
 * Motion menu, has all the methods related to the robot movement
 */
void Menu::Motion_Menu() {
	std::string menu_text = "Motion Menu\n0. Stop\n1. Move Left\n2. Move Backward\n3. Move Right\n"
		"4. Turn Left\n5. Move Forward\n6. Turn Right\n7. Move Forward Safe\n8. Move Backward Safe\n9. Back\n";


	//	"7. Move Forward Safe  8. Move Backward Safe  9. Back"
	//	"4. Turn Left          5. Move Forward        6. Turn Right"
	//	"1. Move Left          2. Move Backward       3. Move Right";
	//  "0. Stop"

	bool loop = true;
	while (loop) {

		int choice = 0;
		std::cout << menu_text << "Choose one: ";
		std::cin >> choice;
		std::cout << "\n";

		switch (choice) {
		case 0:
			robot_controller->stop();
			break;
		case 1:
			robot_controller->moveLeft();
			break;
		case 2:
			robot_controller->moveBackward();
			break;
		case 3:
			robot_controller->moveRight();
			break;
		case 4:
			robot_controller->turnLeft();
			break;
		case 5:
			robot_controller->moveForward();
			break;
		case 6:
			robot_controller->turnRight();
			break;
		case 7:
			safe_navigation->moveForwardSafe();
			break;
		case 8:
			safe_navigation->moveBackwardSafe();
			break;
		case 9:
			robot_controller->stop();
			std::cout << "Back\n";
			loop = false;
			break;
		case 10:
			// Dev shortcut for update map
			robot_controller->stop();
			Sleep(100);
			mapper->updateMap();
			break;
		default:
			std::cout << "Invalid option, enter again\n\n";
		}
	}
	// Back, returns to the main menu
}


/*!
 * Sensor menu, users can print sensors values and display the map
 * update sensor values and update and record the map 
 */
void Menu::Sensor_Menu() {
	std::string menu_text = "Sensor Menu\n1. Print IR sensor\n2. Print Lidar sensor\n3. Show Map\n"
		"4. Update Sensors\n5. Update Map\n6. Record map\n7. Back\n";

	bool loop = true;
	while (loop) {

		int choice = 0;
		std::cout << menu_text << "Choose one: ";
		std::cin >> choice;
		std::cout << "\n";

		switch (choice) {
		case 1:
			if (robot_controller->getAccessState() == false) {
				std::cerr << "Access denied. Cannot print IR sensor\n";
				break;
			}
			for (int i = 0; i < 9; i++) {
				std::cout << "IR Sensor " << i << " : " << ir_sensor->getSensorValue(i) << "\n";
			}
			break;
		case 2:
			if (robot_controller->getAccessState() == false) {
				std::cerr << "Access denied. Cannot print Lidar sensor\n";
				break;
			}
			for (int i = 0; i < 667; i++) {
				std::cout << "Lidar Sensor " << i << " : " << lidar_sensor->getSensorValue(i) << "\n";
			}
			break;
		case 3:
			mapper->showMap();
			break;
		case 4:
			robot_controller->updateSensors();
			break;
		case 5:
			mapper->updateMap();
			break;
		case 6:
			mapper->recordMap();
			break;
		case 7:
			std::cout << "Back\n";
			loop = false;
			break;
		default:
			std::cout << "Invalid option, enter again\n\n";
		}
	}
	// Back, returns to the main menu
}

// Deletes objects
Menu::~Menu() {
	delete ir_sensor;
	delete robot_controller;
	delete lidar_sensor;
	delete safe_navigation;
	delete mapper;
}
#include "Menu.h"


Menu::Menu(FestoRobotAPI* robotAPI) :
	robotAPI(robotAPI){
	
	is_robot_connected = false;
	robot_controller = new RobotController(robotAPI);

	Main_Menu();
}


void Menu::create_objects() {
	ir_sensor = new IRSensor(robotAPI);
	lidar_sensor = new LidarSensor(robotAPI);
	safe_navigation = new SafeNavigation(robot_controller, ir_sensor);
	mapper = new Mapper(robot_controller, *lidar_sensor);
}


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
				std::cout << "Can't use other menus before connecting to the robot\n\n";
				break;
			}
			Motion_Menu();
			break;
		case 3:
			if (!is_robot_connected) {
				std::cout << "Can't use other menus before connecting to the robot\n\n";
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


void Menu::Connection_Menu() {
	std::string menu_text = "Connection Menu\n1. Connect Robot\n2. Disconnect Robot\n3. Back\n";

	bool loop = true;
	while (loop) {

		int choice = 0;
		std::cout << menu_text << "Choose one: ";
		std::cin >> choice;
		std::cout << "\n";

		switch (choice) {
		case 1:
			std::cout << "<Connect>\n";
			if (robot_controller->connectRobot()) {
				is_robot_connected = true;
			}
			create_objects();
			break;
		case 2:
			std::cout << "<Disconnect>\n";
			robot_controller->disconnectRobot();
			break;
		case 3:
			std::cout << "Back\n";
			loop = false;
			break;
		default:
			std::cout << "Invalid option, enter again\n\n";
		}
	}

	// Back, returns to the main menu
}


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
			mapper->updateMap();
		default:
			std::cout << "Invalid option, enter again\n\n";
		}
	}
	// Back, returns to the main menu
}


void Menu::Sensor_Menu() {
	std::string menu_text = "Sensor Menu\n1. Print IR sensor\n2. Print Lidar sensor\n3. Show Map\n"
		"4. Update IR Sensor\n5. Update lidar Sensor\n6. Update Map\n7. Record map\n8. Back\n";

	bool loop = true;
	while (loop) {

		int choice = 0;
		std::cout << menu_text << "Choose one: ";
		std::cin >> choice;
		std::cout << "\n";

		switch (choice) {
		case 1:
			for (int i = 0; i < 9; i++) {
				std::cout << "IR Sensor " << i << " : " << ir_sensor->getRange(i) << "\n";
			}
			break;
		case 2:
			for (int i = 0; i < 667; i++) {
				std::cout << "Lidar Sensor " << i << " : " << lidar_sensor->getRange(i) << "\n";
			}
			break;
		case 3:
			mapper->showMap();
			break;
		case 4:
			ir_sensor->update();
			break;
		case 5:
			lidar_sensor->update();
			break;
		case 6:
			mapper->updateMap();
			break;
		case 7:
			mapper->recordMap();
			break;
		case 8:
			std::cout << "Back\n";
			loop = false;
			break;
		default:
			std::cout << "Invalid option, enter again\n\n";
		}
	}
	// Back, returns to the main menu
}

void Menu::Quit() {
	// Quit
	delete ir_sensor;
	delete robot_controller;
	delete lidar_sensor;
	delete safe_navigation;
	delete mapper;
}
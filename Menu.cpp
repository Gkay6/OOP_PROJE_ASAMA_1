#include "Menu.h"

FestoRobotAPI* robotAPI;
LidarSensor* lidar_sensor;
IRSensor* ir_sensor;
RobotController* robot_controller;
SafeNavigation* safe_navigation;


Menu::Menu(FestoRobotAPI* robotAPI) :
	robotAPI(robotAPI), 
	lidar_sensor(robotAPI),
	ir_sensor(robotAPI),
	robot_controller(robotAPI),
	safe_navigation(&robot_controller, &ir_sensor) {

	Main_Menu();
}


void Menu::Main_Menu() {
	std::string menu_text = "Main Menu\n1. Connection\n2. Motion\n3. Sensor\n4. Quit\n";

	bool loop = true;
	while (loop) {
		int choice = 0;
		std::cout << menu_text << "Choose one: ";
		std::cin >> choice;

		switch (choice) {
		case 1:
			Connection_Menu();
			break;
		case 2:
			Motion_Menu();
			break;
		case 3:
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

		switch (choice) {
		case 1:
			std::cout << "<Connect>\n";
			robot_controller.connectRobot();
			break;
		case 2:
			std::cout << "<Disconnect>\n";
			robot_controller.disconnectRobot();
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
	std::string menu_text = "Motion Menu\n0. Stop\n1. Move Left\n2. Move Backward\n3. Move Left\n"
		"4. Turn Left\n5. Move Forward\n6. Turn Right\n7. Move Forward Safe\n8. Move Backward Safe\n9. Back\n";


	//std::string menu_text = 
	//	"7. Move Forward Safe  8. Move Backward Safe  9. Back\n"
	//	"4. Turn Left          5. Move Forward        6. Turn Right\n"
	//	"1. Move Left          2. Move Backward       3. Move Right\n";

	bool loop = true;
	while (loop) {
		int choice = 0;
		std::cout << menu_text << "Choose one: ";
		std::cin >> choice;

		switch (choice) {
		case 0:
			robot_controller.stop();
			break;
		case 1:
			robot_controller.moveLeft();
			break;
		case 2:
			robot_controller.moveBackward();
			break;
		case 3:
			robot_controller.moveRight();
			break;
		case 4:
			robot_controller.turnLeft();
			break;
		case 5:
			robot_controller.moveForward();
			break;
		case 6:
			robot_controller.turnRight();
			break;
		case 7:
			safe_navigation.moveForwardSafe();
			break;
		case 8:
			safe_navigation.moveBackwardSafe();
			break;
		case 9:
			robot_controller.stop();
			std::cout << "Back\n";
			loop = false;
			break;
		default:
			std::cout << "Invalid option, enter again\n\n";
		}
	}
	// Back, returns to the main menu
}


void Menu::Sensor_Menu() {
	std::string menu_text = "Sensor Menu\n1. Print IR sensor\n2. Update IR Sensor\n3. Back\n";

	bool loop = true;
	while (loop) {
		int choice = 0;
		std::cout << menu_text << "Choose one: ";
		std::cin >> choice;

		switch (choice) {
		case 1:
			for (int i = 0; i < 9; i++) {
				std::cout << "IR Sensor " << i << " : " << ir_sensor.getRange(i) << "\n";
			}
			break;
		case 2:
			ir_sensor.update();
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

void Menu::Quit() {
	// Quit
	// this->~Menu();
}
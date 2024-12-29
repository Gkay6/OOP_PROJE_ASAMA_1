/**
 * @file RobotController.h
 * @brief Header file for the RobotController class.
 *
 * @author Sefa Çelenk, Utku Bugra Namkazan
 * @date 24.12.2024
 *
 * This file contains the declaration of the RobotController class, which manages robot
 * operations, sensors, and access control. The class provides an interface to control
 * robot movement, interact with sensors, and manage the robot's connection and authentication.
 */

 /**
  * @class RobotController
  * @brief Manages robot operations, sensors, and access control.
  *
  * This class is responsible for controlling the robot's movements (e.g., forward, backward, turn),
  * handling sensor updates (adding, updating sensors), and managing access control through password authentication.
  * The RobotController interacts with the RobotInterface API and maintains a list of sensors attached to the robot.
  * It also allows operators to command the robot's actions and check its status.
  */
class RobotController {
private:
    std::list<SensorInterface*> &sensorList; ///< List of sensors attached to the robot.
    RobotInterface* robot; ///< Robot API interface.
    RobotOperator robotOperator; ///< Operator responsible for controlling the robot.

public:
    /**
     * @brief Constructor for RobotController.
     *
     * Initializes the robot controller with a specific robot interface, a list of sensors, and an operator.
     *
     * @param _sensorList A reference to the list of sensors attached to the robot.
     * @param api The robot API interface for communication with the robot hardware.
     * @param surname The surname of the operator controlling the robot.
     * @param code A code for the robot operator, used for access control.
     */
    RobotController(std::list<SensorInterface*> &_sensorList, RobotInterface* api, const string& surname, int code);

    /**
     * @brief Turns the robot left.
     *
     * This method rotates the robot 90 degrees to the left.
     */
    void turnLeft();

    /**
     * @brief Turns the robot right.
     *
     * This method rotates the robot 90 degrees to the right.
     */
    void turnRight();

    /**
     * @brief Moves the robot forward.
     *
     * This method moves the robot in the forward direction.
     */
    void moveForward();

    /**
     * @brief Moves the robot backward.
     *
     * This method moves the robot in the backward direction.
     */
    void moveBackward();

    /**
     * @brief Moves the robot to the left.
     *
     * This method moves the robot in the left direction.
     */
    void moveLeft();

    /**
     * @brief Moves the robot to the right.
     *
     * This method moves the robot in the right direction.
     */
    void moveRight();

    /**
     * @brief Stops the robot's movement.
     *
     * This method halts any movement of the robot.
     */
    void stop();

    /**
     * @brief Gets the current pose of the robot.
     *
     * This method retrieves the current position and orientation of the robot.
     *
     * @return The current pose of the robot (position and orientation).
     */
    Pose getPose() const;

    /**
     * @brief Prints information about the robot.
     *
     * This method prints the robot's current status, including its pose and other relevant details.
     */
    void print() const;

    /**
     * @brief Connects to the robot.
     *
     * This method establishes a connection with the robot's API for communication.
     *
     * @return True if the connection is successful, false otherwise.
     */
    bool connectRobot();

    /**
     * @brief Disconnects from the robot.
     *
     * This method terminates the connection to the robot.
     *
     * @return True if the disconnection is successful, false otherwise.
     */
    bool disconnectRobot();

    /**
     * @brief Adds a sensor to the robot.
     *
     * This method adds a new sensor to the robot's sensor list.
     *
     * @param sensor A pointer to the sensor to be added to the robot.
     */
    void addSensor(SensorInterface* sensor);

    /**
     * @brief Updates all sensors attached to the robot.
     *
     * This method iterates through the list of attached sensors and updates their data.
     */
    void updateSensors();

    /**
     * @brief Opens access to the robot using a password.
     *
     * This method authenticates the operator by comparing the provided password with the correct one.
     *
     * @param password The password used to grant access to the robot.
     * @return True if access is granted, false if the password is incorrect.
     */
    bool openAccess(int password);

    /**
     * @brief Closes access to the robot using a password.
     *
     * This method closes the access control, preventing further commands from being issued to the robot.
     *
     * @param password The password used to close access to the robot.
     * @return True if access is successfully closed, false if the password is incorrect.
     */
    bool closeAccess(int password);

    /**
     * @brief Gets the current access state of the robot.
     *
     * This method checks whether the robot's access is currently open or closed.
     *
     * @return True if access is open, false if access is closed.
     */
    bool getAccessState();
};

/**
 * @brief Test function for RobotController.
 *
 * This function tests the functionality of the RobotController by simulating commands such as movement, 
 * sensor updates, and access control operations.
 *
 * @param robotino The robot controller object to be tested.
 */
void RobotControllerTest(RobotController& robotino);


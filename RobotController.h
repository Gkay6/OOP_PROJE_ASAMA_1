/*!
 * \file RobotController.h
 * \author Sefa Çelenk
 * \date 20.12.2024
 * \brief Header file for the RobotController class, which manages the control and state of a robot using the FestoRobotAPI.
 */

#ifndef ROBOTCONTROLLER_H
#define ROBOTCONTROLLER_H

#include "Pose.h"
#include "FestoRobotAPI.h"

/*!
 * \class RobotController
 * \brief Manages the control and state of a robot using the FestoRobotAPI.
 */
class RobotController {
private:
    Pose* position;           //!< Pointer to the robot's current pose
    FestoRobotAPI* robotAPI;  //!< Pointer to the Festo Robot API, provided externally
    bool connectionStatus;    //!< Status indicating if the robot is connected

public:
    /*!
     * \brief Constructor that initializes the RobotController with a given API object.
     * \param api Pointer to an instance of FestoRobotAPI.
     */
    RobotController(FestoRobotAPI* api);

    /*!
     * \brief Destructor to clean up resources.
     */
    ~RobotController();

    /*!
     * \brief Commands the robot to turn left.
     */
    void turnLeft();

    /*!
     * \brief Commands the robot to turn right.
     */
    void turnRight();

    /*!
     * \brief Commands the robot to move forward.
     */
    void moveForward();

    /*!
     * \brief Commands the robot to move backward.
     */
    void moveBackward();

    /*!
     * \brief Commands the robot to move left.
     */
    void moveLeft();

    /*!
     * \brief Commands the robot to move right.
     */
    void moveRight();

    /*!
     * \brief Stops the robot's movement.
     */
    void stop();

    /*!
     * \brief Retrieves the current pose of the robot.
     * \return The current Pose of the robot.
     */
    Pose getPose() const;

    /*!
     * \brief Prints the current state of the robot to the console.
     */
    void print() const;

    /*!
     * \brief Connects the robot to the API.
     * \return True if the connection is successful, false otherwise.
     */
    bool connectRobot();

    /*!
     * \brief Disconnects the robot from the API.
     * \return True if the disconnection is successful, false otherwise.
     */
    bool disconnectRobot();
};

/*!
 * \brief Test function for the RobotController class.
 * \author Sefa Çelenk
 * \param robotino Reference to a RobotController object to test.
 */
void RobotControllerTest(RobotController& robotino);

#endif // ROBOTCONTROLLER_H

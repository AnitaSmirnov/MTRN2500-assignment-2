// Assignment 1 XBoxController.cpp
// Anita Smirnov z5164903

#include <iostream>
#include <Windows.h>
#include <xinput.h>
#include <math.h>
#include "XInputWrapper.h"
#include "XBoxController.hpp"

using namespace std;
XINPUT_STATE State;
XINPUT_VIBRATION Vibration;

// The constructor creates an object of the XBoxController type
GamePad::XBoxController::XBoxController(XInputWrapper* xinput, DWORD id) {
	this->xinput = xinput;
	this->id = id;
}

// Returns the id of the controller
DWORD GamePad::XBoxController::GetControllerId() {
	return this->id;
}

// Checks if the controller is connected
bool GamePad::XBoxController::IsConnected() {
	int check = false;
	// ERROR_SUCESS means that the operation completed successfully
	// So this would mean that the controller is connected
	if (XInputGetState(id, &State) == ERROR_SUCCESS) {
		cout << "Controller " << id << " is connected" << endl;
		check = true;
	}
	return check; 
}

// Finds the location of the left thumbstick
GamePad::Coordinate GamePad::XBoxController::LeftThumbLocation() {
	xinput->XInputGetState(id, &State);
	SHORT x = State.Gamepad.sThumbLX;
	SHORT y = State.Gamepad.sThumbLY;
	// Finding the magnitude/modulus of the "vector" of the thumbstick
	float magnitude = float(sqrt(x * x + y * y));
	// Storing the direction of the vector
	float cos = float(x) / magnitude;
	float sin = float(y) / magnitude;

	// If the modulus is within the deadzone, set values to 0
	if (magnitude <= float(this->Deadzone)) {
		magnitude = 0;
	} else {
		// If the modulus is above the maximum value, magnitude = maximum
		if (magnitude > this->Max) magnitude = this->Max;
		// Adjust modulus relative to the end of the dead zone
		magnitude -= float(this->Deadzone);
	}

	// Normalize the magnitude with respect to its expected range
	// Magnitude/(Max - Deadzone) scales to a range of 0 to 1
	// Multiplying by Max givesa magnitude value of 0 to (Max = 32767)
	magnitude = magnitude * this->Max / (this->Max - float(this->Deadzone));
	x = SHORT(cos * magnitude); // x = r cos, keeping the direction
	y = SHORT(sin * magnitude); // y = r sin, keeping the direction
	return GamePad::Coordinate(x, y);
}

// Finds the location of the right thumbstick
GamePad::Coordinate GamePad::XBoxController::RightThumbLocation() {
	xinput->XInputGetState(id, &State);
	SHORT x = State.Gamepad.sThumbRX;
	SHORT y = State.Gamepad.sThumbRY;
	// Finding the magnitude/modulus of the "vector" of the thumbstick
	float magnitude = float(sqrt(x * x + y * y));
	// Storing the direction of the vector
	float cos = float(x) / magnitude;
	float sin = float(y) / magnitude;

	// If the modulus is within the deadzone, set values to 0
	if (magnitude <= float(this->Deadzone)) {
		magnitude = 0;
	} else {
		// If the modulus is above the maximum value, magnitude = maximum
		if (magnitude > this->Max) magnitude = this->Max;
		// Adjust modulus relative to the end of the dead zone
		magnitude -= float(this->Deadzone);
	}

	// Normalize the magnitude with respect to its expected range
	// Magnitude/(Max - Deadzone) scales to a range of 0 to 1
	// Multiplying by Max givesa magnitude value of 0 to (Max = 32767)
	magnitude = magnitude * this->Max / (this->Max - float(this->Deadzone));
	x = SHORT(cos * magnitude); // x = r cos, keeping the direction
	y = SHORT(sin * magnitude); // y = r sin, keeping the direction
	return GamePad::Coordinate(x, y);
}


// Sets values to modify the vibration of the controller
// Ranging from 0 to 65535
void GamePad::XBoxController::Vibrate(WORD left, WORD right) {
	xinput->XInputGetState(id, &State);
	Vibration.wLeftMotorSpeed = left;
	Vibration.wRightMotorSpeed = right;
	XInputSetState(id, &Vibration);
}

// Sets the deadzone of the controller to help eliminate random
// values/outputs from the thumbsticks when in the neutral position
void GamePad::XBoxController::SetDeadzone(unsigned int radius) {
	xinput->XInputGetState(id, &State);
	// If the value < radius, it's in the dead zone; set value to 0
	this->Deadzone = radius;
}


// Checks if the A button is pressed
bool GamePad::XBoxController::PressedA() {
	xinput->XInputGetState(id, &State);
	// Bitmask 0x1000
	if (State.Gamepad.wButtons & XINPUT_GAMEPAD_A) return TRUE;
	else return FALSE;
}

// Checks if the B button is pressed
bool GamePad::XBoxController::PressedB() {
	xinput->XInputGetState(id, &State);
	// Bitmask 0x2000
	if (State.Gamepad.wButtons & XINPUT_GAMEPAD_B) return TRUE;
	else return FALSE;
}

// Checks if the X button is pressed
bool GamePad::XBoxController::PressedX() {
	xinput->XInputGetState(id, &State);
	// Bitmask 0x4000
	if (State.Gamepad.wButtons & XINPUT_GAMEPAD_X) return TRUE;
	else return FALSE;
}

// Checks if the Y button is pressed
bool GamePad::XBoxController::PressedY() {
	xinput->XInputGetState(id, &State);
	// Bitmask 0x8000
	if (State.Gamepad.wButtons & XINPUT_GAMEPAD_Y) return TRUE;
	else return FALSE;
}

// Checks if the left shoulder button is pressed
bool GamePad::XBoxController::PressedLeftShoulder() {
	xinput->XInputGetState(id, &State);
	// Bitmask 0x0100
	if (State.Gamepad.wButtons & XINPUT_GAMEPAD_LEFT_SHOULDER) return TRUE;
	else return FALSE;
}

// Checks if the right shoulder button is pressed
bool GamePad::XBoxController::PressedRightShoulder() {
	xinput->XInputGetState(id, &State);
	// Bitmask 0x0200
	if (State.Gamepad.wButtons & XINPUT_GAMEPAD_RIGHT_SHOULDER) return TRUE;
	else return FALSE;
}

// Checks if the left Dpad is pressed
bool GamePad::XBoxController::PressedLeftDpad() {
	xinput->XInputGetState(id, &State);
	// Bitmask 0x0004
	if (State.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_LEFT) return TRUE;
	else return FALSE;
}

// Checks if the right Dpad is pressed
bool GamePad::XBoxController::PressedRightDpad() {
	xinput->XInputGetState(id, &State);
	// Bitmask 0x0008
	if (State.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_RIGHT) return TRUE;
	else return FALSE;
}

// Checks if the up Dpad is pressed
bool GamePad::XBoxController::PressedUpDpad() {
	xinput->XInputGetState(id, &State);
	// Bitmask 0x0001
	if (State.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_UP) return TRUE;
	else return FALSE;
}

// Checks if the down Dpad is pressed
bool GamePad::XBoxController::PressedDownDpad() {
	xinput->XInputGetState(id, &State);
	// Bitmask 0x0002
	if (State.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_DOWN) return TRUE;
	else return FALSE;
}

// Checks if the start button is pressed
bool GamePad::XBoxController::PressedStart() {
	xinput->XInputGetState(id, &State);
	// Bitmask 0x0010
	if (State.Gamepad.wButtons & XINPUT_GAMEPAD_START) return TRUE;
	else return FALSE;
}

// Checks if the back button is pressed
bool GamePad::XBoxController::PressedBack() {
	xinput->XInputGetState(id, &State);
	// Bitmask 0x0020
	if (State.Gamepad.wButtons & XINPUT_GAMEPAD_BACK) return TRUE;
	else return FALSE;
}

// Checks if the left thumbstick is pressed
bool GamePad::XBoxController::PressedLeftThumb() {
	xinput->XInputGetState(id, &State);
	// Bitmask 0x0040
	if (State.Gamepad.wButtons & XINPUT_GAMEPAD_LEFT_THUMB) return TRUE;
	else return FALSE;
}

// Checks if the right thumbstick is pressed
bool GamePad::XBoxController::PressedRightThumb() {
	xinput->XInputGetState(id, &State);
	// Bitmask 0x0080
	if (State.Gamepad.wButtons & XINPUT_GAMEPAD_RIGHT_THUMB) return TRUE;
	else return FALSE;
}

// Finds the location of the left trigger, ranging from 0 to 255
BYTE GamePad::XBoxController::LeftTriggerLocation() {
	xinput->XInputGetState(id, &State);
	return State.Gamepad.bLeftTrigger;
}

// Finds the location of the right trigger, ranging from 0 to 255
BYTE GamePad::XBoxController::RightTriggerLocation() {
	xinput->XInputGetState(id, &State);
	return State.Gamepad.bRightTrigger;
}

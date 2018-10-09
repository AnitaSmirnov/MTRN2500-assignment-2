#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <map>


#ifdef __APPLE__
	#include <OpenGL/gl.h>
	#include <OpenGL/glu.h>
	#include <GLUT/glut.h>
	#include <unistd.h>
	#include <sys/time.h>
#elif defined(WIN32)
	#include <Windows.h>
	#include <tchar.h>
	#include <GL/gl.h>
	#include <GL/glu.h>
	#include <GL/glut.h>
#else
	#include <GL/gl.h>
	#include <GL/glu.h>
	#include <GL/glut.h>
	#include <unistd.h>
	#include <sys/time.h>
#endif


#include "Camera.hpp"
#include "Ground.hpp"
#include "KeyManager.hpp"
#include "XBoxController.hpp"

#include "Shape.hpp"
#include "Vehicle.hpp"

#include "RemoteDataManager.hpp"
#include "Messages.hpp"
#include "HUD.hpp"
#include "ObstacleManager.hpp"

#include "RectangularPrism.hpp"
#include "TrapezoidalPrism.hpp"
#include "TriangularPrism.hpp"
#include "Cylinder.hpp"
#include "MyVehicle.hpp"

void display();
void reshape(int width, int height);
void idle();

void keydown(unsigned char key, int x, int y);
void keyup(unsigned char key, int x, int y);
void special_keydown(int keycode, int x, int y);
void special_keyup(int keycode, int x, int y);

void mouse(int button, int state, int x, int y);
void dragged(int x, int y);
void motion(int x, int y);

void follow();

using namespace std;
using namespace scos;

// Used to store the previous mouse location so we
//   can calculate relative mouse movement.
int prev_mouse_x = -1;
int prev_mouse_y = -1;

// vehicle control related variables
Vehicle * vehicle = NULL;
double speed = 0;
double steering = 0;

// default goal location
std::deque<GoalState> goals;

std::map<int, Vehicle *> otherVehicles;

int frameCounter = 0;

//int _tmain(int argc, _TCHAR* argv[]) {
int main(int argc, char ** argv) {
	XInputWrapper xinput; //create an instantiation of the wrapper
	GamePad::XBoxController controller0(&xinput, 0); //create a new xbox controller object, passing in a pointer to the wrapper
	const int WINDOW_WIDTH = 800;
	const int WINDOW_HEIGHT = 600;

	glutInit(&argc, (char**)(argv));
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	glutCreateWindow("MTRN3500 - GL");

	Camera::get()->setWindowDimensions(WINDOW_WIDTH, WINDOW_HEIGHT);

	glEnable(GL_DEPTH_TEST);

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutIdleFunc(idle);

	glutKeyboardFunc(keydown);
	glutKeyboardUpFunc(keyup);
	glutSpecialFunc(special_keydown);
	glutSpecialUpFunc(special_keyup);

	glutMouseFunc(mouse);
	glutMotionFunc(dragged);
	glutPassiveMotionFunc(motion);

	// -------------------------------------------------------------------------
	// Please uncomment the following line of code and replace 'MyVehicle'
	//   with the name of the class you want to show as the current 
	//   custom vehicle.
	// -------------------------------------------------------------------------

	vehicle = new MyVehicle();


	// add test obstacles
	ObstacleManager::get()->addObstacle(Obstacle(10,10, 1));
	ObstacleManager::get()->addObstacle(Obstacle(10,-10, 1));
	ObstacleManager::get()->addObstacle(Obstacle(-10,10, 1));
	ObstacleManager::get()->addObstacle(Obstacle(-10,-10, 1));

	// add test goal
	GoalState g;
	g.x = 25;
	g.z = 0;
	goals.push_back(g);


	glutMainLoop();

	if (vehicle != NULL) {
		delete vehicle;
	}

	return 0;
}

void drawGoals()
{
	for (int i = 0; i < goals.size(); ++i) {
		GoalState goal = goals[i];

		glPushMatrix();
		glTranslatef(goal.x, 0, goal.z);
		glRotated(90, -1, 0, 0);
		static GLUquadric * quad = gluNewQuadric();

		// make first goal purple
		if (i == 0)
			glColor3f(1, .3, 1);
		else
			glColor3f(1, 1, 1);

		gluCylinder(quad, .5, .5, 10, 5, 1);
		glPopMatrix();
	}
}

// define new draw functions here

void drawTest() {

	TrapezoidalPrism test2(20.0, 0.0, 20.0, 3.0, 1.0, 5.0, 2.0, 1.0, 36.0, 0.8, 0.4, 0.6);
	for (int i = 0; i < 10; i++) {
		test2.setColor(i/10, 1.0 - i/10, 0.1 * i);
		test2.setColorInGL();
		test2.draw();
	}

	TrapezoidalPrism test3(15.0, 0.0, 15.0, 3.0, 1.0, 5.0, 2.0, 1.0, 360/8, 0.8, 0.4, 0.6);
	for (int j = 0; j < 8; j++) {
		test3.setColor(j / 10, 1.0 - j / 10, 1);
		test3.setColorInGL();
		test3.draw();
	}

	TrapezoidalPrism test4(10.0, 0.0, 10.0, 3.0, 1.0, 5.0, 2.0, 1.0, 60, 0.8, 0.4, 0.6);
	for (int j = 0; j < 6; j++) {
		test4.setColor(1, 1.0 - j / 10, 1- j/10);
		test4.setColorInGL();
		test4.draw();
	} 
}

void drawTestTrig() {
	TriangularPrism test5(0.0, 0.0, 0.0, 10.0, 15.0, 15.0, 6.0, 0.0, 0.8, 1, 0.6);
	test5.setColor(0.3, 0.0, 1.0);
	test5.setColorInGL();
	test5.draw();
}

void drawTestCylinder() {
	Cylinder test6(2.0, 5.5, 2.0, 20.0, 10.0, 0.0, 1.0, 1.0, 1.0, 1, 1);
	test6.setColor(0.3, 0.0, 1.0);
	test6.setColorInGL();
	test6.draw();
}

void drawCar() {
	MyVehicle vroom();
}

void drawTask1() {
	RectangularPrism a(20.0, 0.0, 20.0, 10.0, 10.0, 10.0, 0.0, 1.0, 0.0, 0.5);
	a.setColor(1.0, 0.0, 0.0);
	a.setColorInGL();
	a.draw();

	TriangularPrism b(-20.0, 0.0, 20.0, 10.0, 15.0, 20.0, 6.0, 90.0, 1, 0.6, 0.9);
	b.setColor(0.0, 1.0, 0.0);
	b.setColorInGL();
	b.draw();

	TrapezoidalPrism test2(-20.0, 0.0, -20.0, 3.0, 1.0, 5.0, 2.0, 1.0, 0.0, 0.2, 1, 0);
	test2.setColor(0.0, 0.0, 1.0);
	test2.setColorInGL();
	test2.draw();

	Cylinder c(20.0, 0.0, -20.0, 2.0, 1.0, 90.0, 1.0, 1.0, 0.8, 0, 0);
	c.setColor(1.0, 1.0, 1.0);
	c.setColorInGL();
	c.draw();
}

void display() {
	frameCounter++;
	// -------------------------------------------------------------------------
	//  This method is the main draw routine. 
	// -------------------------------------------------------------------------

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	if(Camera::get()->isPursuitMode() && vehicle != NULL) {
		double x = vehicle->getX(), y = vehicle->getY(), z = vehicle->getZ();
		double dx = cos(vehicle->getRotation() * 3.141592765 / 180.0);
		double dy = sin(vehicle->getRotation() * 3.141592765 / 180.0);
		Camera::get()->setDestPos(x + (-20 * dx), y + 15, z + (-20 * dy));
		Camera::get()->setDestDir(dx, -0.25, dy);
	}
	Camera::get()->updateLocation();
	Camera::get()->setLookAt();

	Ground::draw();
	
	// draw other vehicles
	for(std::map<int, Vehicle *>::iterator iter = otherVehicles.begin(); iter != otherVehicles.end(); ++iter) 
		iter->second->draw();

	// draw my vehicle
	if (vehicle != NULL) {
		vehicle->draw();
	}

	// draw obstacles
	ObstacleManager::get()->drawAll();

	// draw goals
	drawGoals();

	// draw HUD
	HUD::Draw();

	// call any new draw functions here!
	//drawTest();
	//drawTestTrig();
	//drawTestCylinder();
	drawCar();
	//drawTask1();

	glutSwapBuffers();
};

void reshape(int width, int height) {

	Camera::get()->setWindowDimensions(width, height);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
};

void remoteDriver(Vehicle * vehicle, double x, double z, double r, double speed_, double steering_)
{
	// filter 
	const double kSmoothingFactor = 0.5;
	vehicle->setX(vehicle->getX() * kSmoothingFactor + x * (1 - kSmoothingFactor));
	vehicle->setZ(vehicle->getZ() * kSmoothingFactor + z * (1 - kSmoothingFactor));

	vehicle->setRotation(r);
	vehicle->steering = steering_;
	vehicle->speed = speed_;
}

double getTime()
{
#if defined(WIN32)
	LARGE_INTEGER freqli;
	LARGE_INTEGER li;
	if(QueryPerformanceCounter(&li) && QueryPerformanceFrequency(&freqli)) {
		return double(li.QuadPart) / double(freqli.QuadPart);
	}
	else {
		static ULONGLONG start = GetTickCount64();
		return (GetTickCount64() - start) / 1000.0;
	}
#else
	struct timeval t;
	gettimeofday(&t, NULL);
	return t.tv_sec + (t.tv_usec / 1000000.0);
#endif
}

void idle() {

	if (KeyManager::get()->isAsciiKeyPressed('a')) {
		Camera::get()->strafeLeft();
	}

	if (KeyManager::get()->isAsciiKeyPressed('c')) {
		Camera::get()->strafeDown();
	}

	if (KeyManager::get()->isAsciiKeyPressed('d')) {
		Camera::get()->strafeRight();
	}

	if (KeyManager::get()->isAsciiKeyPressed('s')) {
		Camera::get()->moveBackward();
	}

	if (KeyManager::get()->isAsciiKeyPressed('w')) {
		Camera::get()->moveForward();
	}

	if (KeyManager::get()->isAsciiKeyPressed(' ')) {
		Camera::get()->strafeUp();
	}

	speed = 0;
	steering = 0;
	XInputWrapper xinput; //create an instantiation of the wrapper
	GamePad::XBoxController controller0(&xinput, 0); //create a new xbox controller object, passing in a pointer to the wrapper
	if (controller0.IsConnected()) {
		if (controller0.PressedY()) {
			speed = Vehicle::MAX_FORWARD_SPEED_MPS;
		}
		else if (controller0.PressedA()) {
			speed = Vehicle::MAX_BACKWARD_SPEED_MPS;
		}
		else {
			speed = 0;
		}

		if (controller0.PressedB()) {
			steering = Vehicle::MAX_RIGHT_STEERING_DEGS * -1;
		}
		else if (controller0.PressedX()) {
			steering = Vehicle::MAX_LEFT_STEERING_DEGS * -1;
		}
		else {
			steering = 0;
		}

	}
	
	if (KeyManager::get()->isSpecialKeyPressed(GLUT_KEY_LEFT)) {
		steering = Vehicle::MAX_LEFT_STEERING_DEGS * -1;
	}

	if (KeyManager::get()->isSpecialKeyPressed(GLUT_KEY_RIGHT)) {
		steering = Vehicle::MAX_RIGHT_STEERING_DEGS * -1;
	}

	if (KeyManager::get()->isSpecialKeyPressed(GLUT_KEY_UP)) {
		speed = Vehicle::MAX_FORWARD_SPEED_MPS;
	}

	if (KeyManager::get()->isSpecialKeyPressed(GLUT_KEY_DOWN)) {
		speed = Vehicle::MAX_BACKWARD_SPEED_MPS;
	}

	


	// attempt to do data communications every 4 frames if we've created a local vehicle
	if(frameCounter % 4 == 0 && vehicle != NULL) {

		// if not connected, attempt to connect every 2 seconds
		if(!RemoteDataManager::IsConnected()) {
			if(frameCounter % 120 == 0) {
		
				// erase other vehicles
				for(std::map<int, Vehicle*>::iterator iter = otherVehicles.begin(); iter  != otherVehicles.end(); ++iter) {
					delete iter->second;
				}
				otherVehicles.clear();

				// uncomment this line to connect to the robotics server.
				RemoteDataManager::Connect("www.robotics.unsw.edu.au","18081");

				// on connect, let's tell the server what we look like
				if (RemoteDataManager::IsConnected()) {
					ObstacleManager::get()->removeAll();

					VehicleModel vm;
					vm.remoteID = 0;

					// student code goes here
					ShapeInit List;
					std::vector<Shape*> ShapeList = dynamic_cast<MyVehicle *>(vehicle)->shapeVector();
					std::vector<Shape*>::iterator it;
					Cylinder *cyl;
					RectangularPrism *rect;
					TrapezoidalPrism *trap;
					TriangularPrism *tri;
					for (int i = 0; i < ShapeList.size(); i++) {
						List.type = UNKNOWN_SHAPE;
						// checking if the shape is a cylinder
						cyl = dynamic_cast<Cylinder*>(ShapeList[i]);
						if (cyl != nullptr) {
							List.type = CYLINDER;
							List.params.cyl.radius = cyl->getRadius();
							List.params.cyl.isRolling = cyl->getRoll();
							List.params.cyl.isSteering = cyl->getSteer();
							List.params.cyl.depth = cyl->getDepth();
						}
						// checking if the shape is a rectangular prism
						rect = dynamic_cast<RectangularPrism*>(ShapeList[i]);
						if (rect != nullptr) {
							List.type = RECTANGULAR_PRISM;
							List.params.rect.xlen = rect->getXLen();
							List.params.rect.ylen = rect->getYLen();
							List.params.rect.zlen = rect->getZLen();
						}
						// checking if the shape is a trapezoidal prism
						trap = dynamic_cast<TrapezoidalPrism*>(ShapeList[i]);
						if (trap != nullptr) {
							List.type = TRAPEZOIDAL_PRISM;
							List.params.trap.alen = trap->getALen();
							List.params.trap.blen = trap->getBLen();
							List.params.trap.aoff = trap->getOffset();
							List.params.trap.depth = trap->getDepth();
							List.params.trap.height = trap->getHeight();

						}
						// checking if the shape is a triangular prism
						tri = dynamic_cast<TriangularPrism*>(ShapeList[i]);
						if (tri != nullptr) {
							List.type = TRIANGULAR_PRISM;
							List.params.tri.alen = tri->getALen();
							List.params.tri.blen = tri->getBLen();
							List.params.tri.angle = tri->getAngle();
							List.params.tri.depth = tri->getDepth();
						}			
						// pushing the shape into the vehicle model if it's a known shape
						if (List.type != UNKNOWN_SHAPE) {
							List.xyz[0] = (float)(ShapeList[i]->getX());
							List.xyz[1] = (float)(ShapeList[i]->getY());
							List.xyz[2] = (float)ShapeList[i]->getZ();
							List.rgb[0] = (float)(ShapeList[i])->getRed();
							List.rgb[1] = (float)(ShapeList[i])->getGreen();
							List.rgb[2] = (float)(ShapeList[i])->getBlue();
							List.rotation = (float)(ShapeList[i])->getRotation();
							vm.shapes.push_back(List);
						}
					}
					
					RemoteDataManager::Write(GetVehicleModelStr(vm));
				}
			}
		}

		// if we're connected, send our vehicle state to the server
		if (RemoteDataManager::IsConnected()) {
			VehicleState vs;
			vs.remoteID = 0;
			vs.x = vehicle->getX();
			vs.z = vehicle->getZ();
			vs.rotation = vehicle->getRotation();
			vs.speed = vehicle->getSpeed();
			vs.steering = vehicle->getSteering();
			RemoteDataManager::Write(GetVehicleStateStr(vs));
		}

		// if we're still connected, receive and handle response messages from the server
		if (RemoteDataManager::IsConnected()) {
			std::vector<RemoteMessage> msgs = RemoteDataManager::Read();
			for(unsigned int i = 0; i < msgs.size(); i++ ) {

				RemoteMessage msg = msgs[i];
				//cout << msg.payload << endl;

				switch(msg.type) {
					// new models
					case 'M':
						{
							std::vector<VehicleModel> models = GetVehicleModels(msg.payload);
							for(unsigned int i = 0; i < models.size(); i++) {
								VehicleModel vm = models[i];
								
								// uncomment the line below to create remote vehicles
								otherVehicles[vm.remoteID] = new MyVehicle(vm);
								// more student code goes here
								//	

							}
							break;
						}

					// vehicle states
					case 'S': 
						{
							std::vector<VehicleState> states = GetVehicleStates(msg.payload);
							for(unsigned int i = 0; i < states.size(); i++) {
								VehicleState vs = states[i];

								std::map<int, Vehicle*>::iterator iter = otherVehicles.find(vs.remoteID);
								if(iter != otherVehicles.end()) {
									Vehicle * veh = iter->second;
									remoteDriver(veh, vs.x, vs.z, vs.rotation, vs.speed, vs.steering);
								}
							}
							break;
						}

					// goal state
					case 'G':
						{
							goals = GetGoals(msg.payload);
							break;
						}

					// obstacle state
					case 'O':
						{
							std::vector<ObstacleState> obs = GetObstacles(msg.payload);
							for(unsigned int i = 0; i < obs.size(); i++) {
								Obstacle o(obs[i].x, obs[i].z, obs[i].radius);
								ObstacleManager::get()->addObstacle(o);
							}
							break;
						}

					// disconnect list
					case 'D':
						{
							std::vector<int> disconnectedIDs = GetVehicleDisconnects(msg.payload);
							for(unsigned int i = 0; i < disconnectedIDs.size(); i++) {
								int id = disconnectedIDs[i];
								std::map<int, Vehicle*>::iterator iter = otherVehicles.find(id);
								if(iter != otherVehicles.end()) {
									delete iter->second;
									otherVehicles.erase(iter);
								}
							}
							break;
						}

					// error message
					case 'E':
						{
							cerr << "Server error: " << msg.payload << endl;
							break;
						}

				}
			} 
		}
	}


	const float sleep_time_between_frames_in_seconds = 0.025;

	static double previousTime = getTime();
	const double currTime = getTime();
	const double elapsedTime = currTime - previousTime;
	previousTime = currTime;

	// do a simulation step
	if (vehicle != NULL) {
		vehicle->update(speed, steering, elapsedTime);
	}
	for(std::map<int, Vehicle*>::iterator iter = otherVehicles.begin(); iter  != otherVehicles.end(); ++iter) {
		iter->second->update(elapsedTime);
	}

	display();

#ifdef _WIN32 
	Sleep(sleep_time_between_frames_in_seconds * 1000);
#else
	usleep(sleep_time_between_frames_in_seconds * 1e6);
#endif
};

void keydown(unsigned char key, int x, int y) {

	// keys that will be held down for extended periods of time will be handled
	//   in the idle function
	KeyManager::get()->asciiKeyPressed(key);

	// keys that react once when pressed rather than need to be held down
	//   can be handles normally, like this...
	switch (key) {
	case 27: // ESC key
		exit(0);
		break;      
	case '0':
		Camera::get()->jumpToOrigin();
		break;
	case 'p':
		Camera::get()->togglePursuitMode();
		break;
	case 'l':
		follow();
		break;
	}

};

void keyup(unsigned char key, int x, int y) {
	KeyManager::get()->asciiKeyReleased(key);
};

void special_keydown(int keycode, int x, int y) {
	KeyManager::get()->specialKeyPressed(keycode);
};

void special_keyup(int keycode, int x, int y) {  
	KeyManager::get()->specialKeyReleased(keycode);  
};

void mouse(int button, int state, int x, int y) {

};

void dragged(int x, int y) {

	if (prev_mouse_x >= 0) {

		int dx = x - prev_mouse_x;
		int dy = y - prev_mouse_y;

		Camera::get()->mouseRotateCamera(dx, dy);
	}

	prev_mouse_x = x;
	prev_mouse_y = y;
};

void motion(int x, int y) {

	prev_mouse_x = x;
	prev_mouse_y = y;
};

void follow() {
	/*
	double curr_x = otherVehicles[0]->getX();
	double curr_y = otherVehicles[0]->getY();
	double curr_z = otherVehicles[0]->getZ();
	otherVehicles[0]->setX((otherVehicles[1]->getX() + curr_x) / 2);
	otherVehicles[0]->setY((otherVehicles[1]->getY() + curr_y) / 2);
	otherVehicles[0]->setZ((otherVehicles[1]->getZ() + curr_z) / 2);
	otherVehicles[0]->setRotation(otherVehicles[1]->getRotation());
	*/

	
}


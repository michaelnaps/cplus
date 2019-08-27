// File: Physics.cpp
// Created by: Michael Napoli
// Created on: 8/11/2019

/*
   Program to test the creation of the 'Force' and 'Kinematics'
   class types and include file.
*/

#include <iostream>
#include <cmath>
using namespace std;

class Force
{
private:
   // VARIABLE INITIALIZATIONS
   double Fx, Fy;
   double netForce;
   double direction;
	const double EPSILON;

   // CALCULATION MEMBER FUNCTIONS

   // Force in the x direction
   void calc_Fx(double temp_F, double temp_dir) {
      double temp_Fx;
      temp_Fx = (temp_F * cos(deg_to_rad(temp_dir)));

      Fx += temp_Fx;
   }
   // Force in the y direction
   void calc_Fy(double temp_F, double temp_dir) {
      double temp_Fy;
      temp_Fy = (temp_F * sin(deg_to_rad(temp_dir)));

      Fy += temp_Fy;
   }
   // calculation for the final direction of the Net Force
   // Error analysis located within thus 
   void calc_direction(double temp_dir) {
      double dir_x, dir_y;

      dir_x = acos(Fx / netForce);
      dir_y = asin(Fy / netForce);
      
      if (fabs(dir_x - dir_y) < EPSILON) {
         direction = rad_to_deg(dir_x);
      }
      else { cout << endl << "ERROR: Direction calculated by the x force and the y force differ." << endl; }
   }
   // Angle functions for converting between degrees and radians
   double deg_to_rad(double deg) {
      return (deg * (M_PI / 180));
   }
   double rad_to_deg(double rad) {
      return (rad * (180 / M_PI));
   }

public:
   // VARIABLE INITIALIZATIONS
   Force() : Fx(0), Fy(0), netForce(0), direction(0), EPSILON(1.2E-8)
   { }

   // SET MEMBER FUNCTIONS
   // set Net Force
   void setForce(double temp_F) { netForce = temp_F; }
   // set Net Direction
   void setDirection(double temp_Dir) { 
      direction = temp_Dir;
   }

   // GET MEMBER FUNCTIONS
   // get Net Force
   double getNetForce() const { return netForce; }
   // get Net Direction
   double getDirection() const { return direction; }

   // ADD NEW FORCE TO CURRENT FORCE
   void addForce(double temp_F, double temp_dir) {
      calc_Fx(temp_F, temp_dir);
      calc_Fy(temp_F, temp_dir);

      netForce = sqrt((Fx * Fx) + (Fy * Fy));

      calc_direction(temp_dir);
   }
};

class Kinematics 
{
private:
   // VARIABLE INITIALIZATIONS
   double velocity_initial;
   double velocity_final;
   double distance_initial;
   double distance_final;
   double distance_total;
   double time;
   double acceleration;
   const double acc_gravity;
	const double EPSILON;

   // CALCULATION MEMBER FUNCTIONS (private)
   // calculate the initial velocity using available class variables
   void calc_velocity_initial() {
      if (velocity_final >= EPSILON && acceleration >= EPSILON && time >= EPSILON)
         { velocity_initial = (velocity_final - (acceleration * time)); }
      else if (distance_total >= EPSILON && acceleration >= EPSILON && time >= EPSILON)
         { velocity_initial = ((distance_total - (0.5 * acceleration * time * time)) / time); }
      else if (distance_total >= EPSILON && velocity_final >= EPSILON && time >= EPSILON)
         { velocity_initial = (((distance_total / time) * 2) - velocity_final); }
      else {
         cout << endl << "ERROR: There is not enough information to calculate the initial velocity." << endl; 
         velocity_initial = 0;
      }
   }
   // calculate final velocity using available class variables
   void calc_velocity_final() {
      if (velocity_initial >= EPSILON && acceleration >= EPSILON && time >= EPSILON)
         { velocity_final = (velocity_initial - (acceleration * time)); }
      else if (distance_total >= EPSILON && velocity_initial && time >= EPSILON)
         { velocity_final = (((distance_total / time) * 2) - velocity_initial); }
      else if (distance_total >= EPSILON && velocity_initial >= EPSILON && acceleration >= EPSILON)
         { velocity_final = ((velocity_initial * velocity_initial) - (2 * acceleration * distance_total)); }
      else {
         cout << endl << "ERROR: There is not enough information to calculate the final velocity." << endl; 
         velocity_final = 0;
      }
   }
   void calc_distance_total() {
	   if (velocity_final >= EPSILON && velocity_initial >= EPSILON && time >= EPSILON) {
         distance_total = (((velocity_final + velocity_initial) / 2) * time);
         distance_final = distance_total - distance_initial;
      }
      else if (velocity_initial >= EPSILON && acceleration >= EPSILON && time >= EPSILON) {
         distance_total = ((velocity_initial * time) + (0.5 * acceleration * time *time));
         distance_final = distance_total - distance_initial;
      }
      else {
         cout << endl << "ERROR: There is not enough information to calculate the distance being called." << endl; 
         distance_total = 0;         
      }
   }
   void calc_distance_initial() {
      if ((distance_initial - (distance_final - distance_total)) >= EPSILON) {
         this->calc_distance_total();
         distance_initial = distance_total - distance_final;
      }
   }
   void calc_distance_final() {
      if ((distance_final - (distance_total + distance_initial)) >= EPSILON) {
         this->calc_distance_total();
         distance_final = distance_total - distance_initial;
      }
   }
   void calc_time() {

   }
   void calc_acceleration() {

   }

public:
   Kinematics() : 
   velocity_initial(0), velocity_final(0),
   distance_initial(0), distance_final(0),
   distance_total(0),
   acceleration(0),
   time(0),
   acc_gravity(9.81),
	EPSILON(1.2E-8)
   { }

   void setVelInitial(double temp_velI) { velocity_initial = temp_velI; }
   void setVelFinal(double temp_velF) { velocity_final = temp_velF; }
   void setDistInitial(double temp_distI) { 
      distance_initial = temp_distI;
      distance_total = distance_final - distance_initial; 
   }
   void setDistFinal (double temp_distF) { 
      distance_final = temp_distF; 
      distance_total = distance_final - distance_initial;
   }
   void setTime (double temp_time) { time = temp_time; }
   void setAcceleration (double temp_acc) { acceleration = temp_acc; }
	
	// 'get' MEMBER FUNCTIONS OF KINEMATICS CLASS
   double getVelInitial() { 
      this->calc_velocity_initial();			// CHECK IF CALCULATION OF VELOCITY IS FUNCTIONING CORRECTLY
      return velocity_initial;
   }
   double getVelFinal() { 
      this->calc_velocity_final();
      return velocity_final;
   }
   double getDist() {
      if ((distance_total - (distance_final - distance_initial)) >= EPSILON) {
         this->calc_distance_total();
         return distance_total;
      }
      else { return distance_total; }
   }
   double getDistInitial() {
      if ((distance_initial - (distance_final - distance_total)) >= EPSILON) {
         this->calc_distance_initial();
         return distance_initial;
      }
      else { return distance_initial; }
   }
   double getDistFinal() { 
      if ((distance_final - (distance_total + distance_initial)) >= EPSILON) {
         this->calc_distance_final();
         return distance_final;
      }      
      else { return distance_final; }
   }
   double getTime() { return time; }
   double getAcceleration() { return acceleration; }
   double getGravityAcceleration() { return acc_gravity; }
	
	void getCommands() {
		
	}
};

int main() 
{ 
   Force F1, F2, F_combine;
   Kinematics test;
   double temp_F, temp_D;
/*
   cout << "Enter Force 1: ";
   cin >> temp_F;
   cout << "Enter direction 1: ";
   cin >> temp_D;

   F1.addForce(temp_F, temp_D);
   F_combine.addForce(temp_F, temp_D);

   cout << "Enter Force 2: ";
   cin >> temp_F;
   cout << "Enter direction 2: ";
   cin >> temp_D;

   F2.addForce(temp_F, temp_D);
   F_combine.addForce(temp_F, temp_D);

   cout << endl << "The combined force is " << F_combine.getNetForce();
   cout << " with a direction of " << F_combine.getDirection() << "." << endl;
*/
   cout << endl << test.getGravityAcceleration() << endl;
   cout << test.getVelInitial() << endl;

   return 0;
}
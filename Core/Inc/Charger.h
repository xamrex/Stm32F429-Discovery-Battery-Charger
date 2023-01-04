/*
 * Charger.h
 *
 *  Created on: 17 gru 2022
 *      Author: Xamrex
 */

#ifndef APPLICATION_USER_CHARGER_H_
#define APPLICATION_USER_CHARGER_H_

#define Vref 1.21f					//vref from ECU
#define CurrentAfterCharging 10 	//-> equals 10mA
#define MaxChargingTime 12   		//12 hrs max charging time
#define MaxBattVoltage 1.7f			//over this voltage it stops charging
#define MinBattVltgForFastCharging 1.0f			//Minimum battery voltage for fast (nominal charging)
#define MinBattVoltage 0.7f					//min batt voltage to starts charging

typedef struct
{
	volatile float BatteryVoltage;  //Battery voltage shown on main screen -> its avg from 10 readings.
	volatile float MaxBatteryVoltage ; // Max batt voltage
	volatile float MinBatteryVotage;
	volatile int LoadingCurrent; //charging current 				VALUE FROM GIU
	volatile int ChargingTime; //Max czas ladowania baterii   	    VALUE FROM GIU [in Hours]
	volatile int ChargeStarted; //Charging started 					VALUE FROM GIU
	volatile int OpAmpVoltageSet;							//if  1, OpAmp Voltage wont change anymore
	volatile float NapiecieBaterii[(60*MaxChargingTime)+1];			//every  1min its filled with batt voltage
	volatile float MeasurementsEverySec[60];								//every  1sec its filled  with batt voltage
	volatile int Passed100ms;										//Flag thats says that 100ms passed
	volatile int PlotPointOnSecGraph;							//if 1, adds point to sec chart
	volatile int PlotPointOnMinutesGraph;							//if 1, adds point to hrs chart
	volatile int ChargingTimeInSec;								//its incrementing form  0 till End
	volatile float ChargingCurrent;									//read charging current w [mA]
	volatile int ChargingCompleted;									//charging is done
	volatile float AverageFromLastMin;							//Average from last 1min
	volatile float VccVoltage;										//Vcc Voltage
	volatile int NoBattFlag;										//no battery flag or Voltage to high

}LadowarkaStruct;

#endif /* APPLICATION_USER_CHARGER_H_ */

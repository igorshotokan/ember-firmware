/* 
 * File:   PrinterStatus.h
 * Author: greener
 *
 * Created on April 1, 2014, 3:09 PM
 */

#ifndef PRINTERSTATUS_H
#define	PRINTERSTATUS_H

#include <stddef.h>
#include <string>

// PrintEngine state machine state names
#define PRINTER_ON_STATE    "PrinterOn"
#define DOOR_CLOSED_STATE   "DoorClosed"
#define INITIALIZING_STATE  "Initializing"
#define DOOR_OPEN_STATE     "DoorOpen"
#define HOMING_STATE        "Homing"
#define HOME_STATE          "Home"
#define IDLE_STATE          "Idle"
#define PRINT_SETUP_STATE   "PrintSetup"
#define MOVING_TO_START_STATE "MovingToStartPosition"
#define EXPOSING_STATE      "Exposing"
#define PRINTING_STATE      "Printing"
#define PAUSED_STATE        "Paused"
#define SEPARATING_STATE    "Separating"
#define ENDING_PRINT_STATE  "EndingPrint"

// keys for PrinterStatus
#define PRINTER_STATUS_KEY     "PrinterStatus"
#define STATE_PS_KEY           "State"
#define CHANGE_PS_KEY          "Change"
#define IS_ERROR_PS_KEY        "IsError"
#define ERROR_CODE_PS_KEY      "ErrorCode"
#define ERROR_PS_KEY           "Error"
#define LAYER_PS_KEY           "Layer"
#define TOAL_LAYERS_PS_KEY     "TotalLayers"
#define SECONDS_LEFT_PS_KEY    "SecondsLeft"
#define JOB_NAME_PS_KEY        "JobName"
#define TEMPERATURE_PS_KEY     "Temperature"
#define UISUBSTATE_PS_KEY      "UISubState"

// UI sub states
#define UISUBSTATE_DOWNLOADING "Downloading"

/// the possible changes in state
enum StateChange
{
    NoChange,
    Entering,
    Leaving,
};

class PrinterStatus
{
public:    
    const char* _state;
    StateChange _change;
    bool _isError;
    int _errorCode;
    const char* _errorMessage;
    int _numLayers;
    int _currentLayer;
    int _estimatedSecondsRemaining;
    const char* _jobName;
    float _temperature;
    const char* _UISubState;
    
    PrinterStatus() :
    _state(""),
    _change(NoChange),
    _isError(false),
    _errorCode(0),
    _errorMessage(""),
    _numLayers(0),
    _currentLayer(0),
    _estimatedSecondsRemaining(0),
    _jobName(""),
    _temperature(0.0f),
    _UISubState("")
    {}
};

#endif	/* PRINTERSTATUS_H */


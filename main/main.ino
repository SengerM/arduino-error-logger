//~ This is just an example demonstration of the ErrorLogger class.

#include "ErrorLogger.h"

ErrorLogger ELog(13); // Create the ErrorLogger object with an LED in pin 13 to indicate when it has occured an error.

void setup() {
	Serial.begin(9600);
}

void loop() {
	ELog.new_error(Error(WARNING, "A warning msg"));
	ELog.new_error(Error(ERROR, "An error msg"));
	for (int i = 0; i<5; i++) { // Report errors one by one in the order they occured.
		delay(500);
		ELog.report_first_error();
	}
	for (int i = 0; i<5; i++) { // See what happens if there are many errors.
		delay(500);
		ELog.new_error(Error(WARNING, "I cannot store that much warnings!"));
	}
	ELog.report_first_error();
	ELog.new_error(Error(WARNING, "Just a warning"));
	ELog.report_all_errors();
	ELog.new_error(Error(WARNING, "Just a warning"));
	ELog.new_error(Error(ERROR, "Just an error"));
	ELog.new_error(Error(FATAL, "This is very wrong!")); // Fatal error!!
	Serial.println("This will never be printed due to the fatal error");
}

/*
 *  
 *  How to use    : The CatLog() function requires a log message to be passed as an argument.
 *                  Log messages passed here will be logged to the file specified by "LOG_FILE".
 *
 *                  The catLog_clear() function deletes all logs output by catLog().
 *                  The file referenced at this time is the file declared with "LOG_FILE".    
 *                  
 *                  You can remove the logging feature by setting the "CATLOG" constant to false. Returns when set to true.
 *
 *                  Currently, this is the only function available, but I plan to add more as time goes on.                    
 * 
 *  Version       : 1.0.0
 *  LICENSE       : https://www.apache.org/licenses/LICENSE-2.0.txt
 *  Creator       : nekogakure
 *  
 */
#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

#define CATLOG true
#define LOG_FILE "catLog.txt"

void catLog_clear();
void catLog(const char *message);
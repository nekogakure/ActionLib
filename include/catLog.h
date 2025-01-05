/*
 *  How to use    : The CatLog() function requires a log message to be passed as an argument.
 *                  Log messages passed here will be logged to the file specified in the ".config" file.
 *                  By default, the log file is "default.log" unless specified otherwise in the ".config" file.
 *
 *                  The catLog_clear() function deletes all logs output by catLog().
 *                  The file referenced at this time is the file declared in the ".config" file or the default file.
 *
 *                  Logging behavior can be controlled via the ".config" file:
 *                    - "LOG_FILE" specifies the log file name.
 *                    - "CATLOG" (1 or 0) enables or disables logging.
 *                  If ".config" is missing or invalid, default settings are used.
 *
 *                  Before using catLog() or catLog_clear(), call the loadConfig() function
 *                  with the path to the configuration file as an argument.
 *
 *  Future plans  : Additional features, such as log levels (INFO, WARNING, ERROR), and dynamic log rotation,
 *                  will be implemented in future versions.
 *
 *  Version       : 1.0.1
 *  LICENSE       : https://www.apache.org/licenses/LICENSE-2.0.txt
 *  Creator       : nekogakure
 *
 */

#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

void catLog_clear();
void catLog(const char *message);
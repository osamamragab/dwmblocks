//Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {
	/*Icon*/	/*Command*/		/*Update Interval*/	/*Update Signal*/
  {"vol: ", "pamixer --get-volume-human", 0, 7},
  {"cpu: ", "sensors | awk '/Core 0/ {print $3}'", 10, 0},
	{"ram: ", "free -h | awk '/^Mem/ { print $3 }' | sed s/i//g",	10, 0},
  {"net: ", "cat /sys/class/net/e*/operstate", 10, 0},
	{"", "date '+%a %d %b - %I:%M %P%t'", 60, 0},
};

//sets delimeter between status commands. NULL character ('\0') means no delimeter.
static char delim[] = " | ";
static unsigned int delimLen = 5;

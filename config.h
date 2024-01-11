// Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {
	// Icon    Command    Update Interval    Update Signal
	{"", "cat /tmp/recordinginfo 2>/dev/null", 0, 9},
	//{"key: ", "setxkbmap -query | awk '/layout/{print $2}'", 0, 8},
	{"", "nettraf", 1, 0},
	{"net: ", "netconnstat", 5, 5},
	// {"not: ", "dunstctl is-paused | sed 's/false/on/; s/true/off/'", 0, 6},
	{"vol: ", "volumectl get", 0, 7},
	{"mem: ", "free -h | awk '/^Mem/{print substr($3, 1, length($3)-1)}'", 10, 0},
	{"cpu: ", "sensors | awk '/Package id/{print $4}'", 10, 0},
	{"bat: ", "batstat", 10, 8},
	{"", "date '+%a %d %b - %H:%M'", 60, 0},
	{"", "echo \"#$((($(date +%s) - $(date -d 2004-06-09 +%s)) / 86400))\"", 60*60, 0},
};

// sets delimeter between status commands. NULL character ('\0') means no delimeter.
static char delim[] = " | ";
static unsigned int delimLen = 5;

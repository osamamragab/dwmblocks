// Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {
	// Icon    Command    Update Interval    Update Signal
	{"", "[ -s /tmp/recordinginfo ] && echo \"[rec: $(sed -n 2p /tmp/recordinginfo)]\"", 0, 9},
	{"key: ", "setxkbmap -query | awk '/layout/{print $2}'", 0, 8},
	{"noti: ", "[ $(dunstctl is-paused) = false ] && echo on || echo off", 0, 6},
	{"vol: ", "pamixer --get-volume-human", 0, 7},
	{"cpu: ", "sensors | awk '/Core 0/{print $3}'", 10, 0},
	{"ram: ", "free -h | awk '/^Mem/{print substr($3, 1, length($3)-1)}'",	10, 0},
	{"net: ", "cat /sys/class/net/e*/operstate", 10, 0},
	{"", "date '+%a %d %b - %I:%M%p'", 60, 0},
};

// sets delimeter between status commands. NULL character ('\0') means no delimeter.
static char delim[] = " | ";
static unsigned int delimLen = 5;

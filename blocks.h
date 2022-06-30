// Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {
	// Icon    Command    Update Interval    Update Signal
	{"", "[ -s /tmp/recordinginfo ] && echo \"[rec: $(sed -n 2p /tmp/recordinginfo)]\"", 0, 9},
	//{"key: ", "setxkbmap -query | awk '/layout/{print $2}'", 0, 8},
	{"", "nettraf", 5, 0},
	{"net: ", "[ \"$(nmcli networking connectivity)\" = none ] && echo off || echo on", 10, 5},
	{"not: ", "[ \"$(dunstctl is-paused)\" = true ] && echo off || echo on", 0, 6},
	{"vol: ", "pamixer --get-volume-human", 0, 7},
	{"mem: ", "free -h | awk '/^Mem/{print substr($3, 1, length($3)-1)}'", 5, 0},
	{"cpu: ", "sensors | awk '/Core 0/{print $3}'", 5, 0},
	{"", "date '+%a %d %b - %H:%M'", 15, 0},
	{"", "echo \"#$((($(date +%s) - $(date -d 2004-06-09 +%s)) / 86400))\"", 60*60, 0},
};

// sets delimeter between status commands. NULL character ('\0') means no delimeter.
static char delim[] = " | ";
static unsigned int delimLen = 5;

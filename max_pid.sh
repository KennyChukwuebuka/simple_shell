#!/bin/bash

max_pid=$(cat /proc/sys/kernel/pid_max)
echo "Max process ID (PID) value: $max_pid"

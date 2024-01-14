# # Check if build dir exists
if [ ! -x "build" ]; then
    mkdir build
fi

# # Check if the server executable exists
if [ ! -x "build/leader" ]; then
    echo "Leader executable not found or not executable."
    {
        cd build
        if [ ! -x "Makefile" ]; then
            cmake ..
            if [ $? -ne 0 ]; then
                echo "Error: CMake configuration failed."
                exit 1
            fi
        fi
        make leader
        if [ $? -ne 0 ]; then
            echo "Error: Make failed. Check the build logs for details."
            exit 1
        fi
    }
fi

# # Check if the client executable exists
if [ ! -x "build/follower" ]; then
    echo "Follower executable not found or not executable."
    {
        cd build
        make follower
        if [ $? -ne 0 ]; then
            echo "Error: Make failed. Check the build logs for details."
            exit 1
        fi
    }
fi

# # Check if log dir exists
if [ ! -x "../logs" ]; then
    mkdir logs
fi

echo "Execution start"

build/leader 37373 > logs/Leader.log &
pid_leader=$!

echo "Leader started. Starting follower"

build/follower 19191 "127.0.0.1" 37373 > logs/Follower.log & 
pid_follower=$!

echo "Follower started. Starting client connection to follower" 
sleep 1

build/client "127.0.0.1" 37373 > logs/Client.log

echo "Awaiting execution to finish"

wait $pid_leader
wait $pid_follower

echo "Finished"
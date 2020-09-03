# StaticLibraryAppTraining

# Use version system such as ExecutionTimerV1.x or ExecutionTimerV2





Instead of mq_open ,mq_receive ,mq_send we can use mgssnd etc.
Link is : https://pubs.opengroup.org/onlinepubs/009695399/functions/msgsnd.html
https://www.youtube.com/watch?v=JbmOegG9-J0


Link that uses mq_ 's with a char array[..]
https://www.softprayog.in/programming/interprocess-communication-using-posix-message-queues-in-linux

Very informative :
https://www.tutorialspoint.com/ipc-using-message-queues

Manual for one of them :

https://pubs.opengroup.org/onlinepubs/009695399/functions/msgrcv.html


Version 3 is the version with mgssnd 


Two message queues one for message char[], and one for long exeTime

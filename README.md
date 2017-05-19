# opi-serial-to-mysql
the purpose is to read serial data from (stm8 and s08R01 receiver) attached to /dev/ttyS01 (which is serial port on orange pi GPIO)  and post it in mysqldatabase



on the raspberry pi I used /dev/ttyAMA0 -- seemed to interfere witch service : 
systemctl stop serial-getty@ttyAMA0systemctl (this way it stops) 


one module (S08R01 (nrf24 similar on aliexpress :)) sends data to receiver module 
the receiver sends output to serial port of orange pi (rpi similar ;))

on the orange pi the data is stored in a mysql-database

to visualise I use http://www.ebrueggeman.com/phpgraphlib/documentation/tutorial-mysql-and-phpgraphlib 


I based the script on the code from  https://github.com/hubbsy/rpiGPIOserial-to-mysql.git 

I installed mysql dev library : apt-get install libmysqlclient-dev 

just type make 
after that
testserial

under web directory is the php script to display data via the webserver 

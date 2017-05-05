# opi-serial-to-mysql

this is an adaptation from https://github.com/hubbsy/rpiGPIOserial-to-mysql.git 

I installed mysql dev library : apt-get install libmysqlclient-dev 

the purpose is to read serial data from (stm8 and s08R01 receiver) attached to /dev/ttyS01 (which is serial port on orange pi GPIO)  and post it in mysqldatabase

just type make 
after that
testserial

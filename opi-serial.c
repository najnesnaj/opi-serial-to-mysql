/* rpiGPIOserial.c
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#include "inc/opi-mysql.h"
#include "inc/opi-uart.h"

#define version "0.1"

#define true 1
#define false 0

#define BUFFERSIZE 32  //read 32 bytes from nrf24 Module

//extern char MODEMDEVICE[BUFFERSIZE];

// global debug flag
// can be set with -d cmd line parameter option
//int DEBUG = 0; // set to 0 to disable debugging printf()s

int main() {

	char packet_buffer;
	int uart0_filestream = -1;
	int exit_program = false;
	int poids=88;
	//const int BUFFERSIZE = 1024;

	char buffer[BUFFERSIZE];
	char rx_buffer[BUFFERSIZE];
        char weight[5];
        char current[2];
	// sort through the options and parameters received from the command line
	int c = 0;
	opterr = 0;

//	strcpy(MODEMDEVICE, "/dev/ttyAMA0");


	// setup the serial port and get filedescriptor for accessing the UART
	if (rpi_uart_setup(&uart0_filestream) == -1) {
		//ERROR - CAN'T OPEN SERIAL PORT
		perror(
				"Error - Unable to open UART.  Ensure it is not in use by another application. ");
	}


	if (uart0_filestream > 0) {
		printf("waiting to receive data via UART.\n");

		int buffer_position = 0;
		int rx_byte_count = 0;
		int i = 0; 
		int gewicht,oudgewicht,gram;
int stroom,oudestroom;
		while (exit_program == false) {

			rx_byte_count = rpi_uart_receive_bytes(&uart0_filestream,
					&rx_byte_count, rx_buffer, BUFFERSIZE);

			if (rx_byte_count > 0) {
				//the first two bytes of every 32 bytes send, are 0 and 1
                                if ((rx_buffer[0]=='a') && (rx_buffer[1]=='c')){
                                        for (i = 0; i < BUFFERSIZE; ++i)
                                        {
                                                printf("%c", rx_buffer[i]);
                                        }
					   weight[0]=rx_buffer[4];
					   weight[1]=rx_buffer[5]; 
					   weight[2]=rx_buffer[6]; 
					   weight[3]=rx_buffer[7]; 
					   gewicht = atoi(weight); 
					   printf("gewicht %d\n",gewicht);
                                           printf("\n");
					   if (gewicht!=oudgewicht)
					   insertDataSQL(gewicht);
					   oudgewicht=gewicht;
                                }
			}
		}

	//	if (DEBUG) {
	//		printf("finished.  The party's over!\n\n");
	//	}

		// Don't forget to clean up
		rpi_uart_close(&uart0_filestream);
	}
	return 0;
}



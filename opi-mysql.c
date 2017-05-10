#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql.h>

void debugTestSQL(int testi) {

	MYSQL *conn;

	MYSQL_RES *res;
	MYSQL_ROW row;
	char insertinstruktie[200];
	char *server = "localhost";
	char *user = "stm8";
	char *password = "stm8"; /* set me first */
	char *database = "metingen";
	conn = mysql_init(NULL);
	/* Connect to database */
	if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0)) {
		fprintf(stderr, "%s\n", mysql_error(conn));
		exit(1);
	}
	/* send SQL query */
	if (mysql_query(conn, "show tables")) {
		fprintf(stderr, "%s\n", mysql_error(conn));
		exit(1);
	}
	res = mysql_use_result(conn);
	/* output table name */
	printf("MySQL Tables in mysql database:\n");
	while ((row = mysql_fetch_row(res)) != NULL)
		printf("%s \n", row[0]);
	/* close connection */
	mysql_free_result(res);
	mysql_close(conn);
}

void insertDataSQL(int weight) {
	char kompleet[200];
	sprintf(kompleet,"insert into gewicht (datum, gewicht) values (UTC_TIMESTAMP,%d)",weight); 
	MYSQL *conn;
	MYSQL_RES *res;
	MYSQL_ROW row;
	char *server = "localhost";
	char *user = "stm8";
	char *password = "stm8"; /* set me first */
	char *database = "metingen";
	conn = mysql_init(NULL);
	/* Connect to database */
	if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0)) {
		fprintf(stderr, "%s\n", mysql_error(conn));
		exit(1);
	}
	//mysql_query(conn, "insert into gewicht (datum, gewicht) values (UTC_TIMESTAMP, 88)");
	mysql_query(conn, kompleet);
	/* close connection */
	res = mysql_use_result(conn);
	mysql_free_result(res);
	mysql_close(conn);
}


//database = metingen
//table = powerusage
//field = datum, current 


void insertCurrentSQL(int current) {
        char kompleet[200];
        sprintf(kompleet,"insert into powerusage (datum, current) values (UTC_TIMESTAMP,%d)",current);
        MYSQL *conn;
        MYSQL_RES *res;
        MYSQL_ROW row;
        char *server = "localhost";
        char *user = "stm8";
        char *password = "stm8"; /* set me first */
        char *database = "metingen";
        conn = mysql_init(NULL);
        /* Connect to database */
        if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0)) {
                fprintf(stderr, "%s\n", mysql_error(conn));
                exit(1);
        }
        //mysql_query(conn, "insert into gewicht (datum, gewicht) values (UTC_TIMESTAMP, 88)");
        mysql_query(conn, kompleet);
        /* close connection */
        res = mysql_use_result(conn);
        mysql_free_result(res);
        mysql_close(conn);
}





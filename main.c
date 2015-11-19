/***************************************************************************
 *   Copyright (C) 2015 by Minttu   
 *   minnttu_@hotmail.com   
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

/***************************************************************************
*
* 1.  NAME
*     Game of Life
* 2.  DESCRIPTION
*	Game of life is the most simple evolution theory model. rules are following.
* The Rules:
*	For a space that is 'populated':
*		Each cell with one or no neighbors dies, as if by loneliness.
*		Each cell with four or more neighbors dies, as if by overpopulation.
*		Each cell with two or three neighbors survives.
*	For a space that is 'empty' or 'unpopulated'
*		Each cell with three neighbors becomes populated. 
*
* Definition of Done:
*	Ohjelma on tallennettu alusta pit‰en versiohallintaan (melell‰‰n koulun SVN-palvelin)
*   Ohjelma koostuu v‰hint‰‰n kolmesta .c ja yhdest‰ .h tiedostosta
*   Ohjelman k‰‰nt‰miseen on Makefile
*   Ohjelma on dokumentoitu hienosti templateen
*   Ohjelmasta on generoitavissa siisti HTML-dokumentti
*
* 6.  VERSIONS
*       Original:
*         10.11.2015 / Minttu
*
*       Version history:
*
*       	10.11.2015 / Minttu
*				Created main, drawing the "table" with first markings (not all correct though). Made also
*				first version of table that has current markings.
*				Also first version of neighbour counting and cell dying/living decision
*				Created a project 2015_e1201352 to svn, not working.
*
****************************************************************************/

/*-------------------------------------------------------------------*
*    HEADER FILES                                                    *
*--------------------------------------------------------------------*/
#include <stdio.h>
#include <ncurses.h>
#include <unistd.h>
/*-------------------------------------------------------------------*
*    GLOBAL VARIABLES                                                *
*--------------------------------------------------------------------*/
/* Control flags */

/* Globaal constants */

/* Globaal variables */

/* Globaal structures */

/*-------------------------------------------------------------------*
*    FUNCTION PROTOTYPES                                             *
*--------------------------------------------------------------------*/

//compile with gcc -l ncurses -o main main.c
/*********************************************************************
*    MAIN PROGRAM                                                      *
**********************************************************************/

int main(void)
{
int x =0;
int y =0;
int apux = 0;
int apuy = 0;
int i = 0;
int table[7][7];
int naapuriapu=0;

initscr();       // Initialize the window
noecho();        // Don't echo any keypresses
curs_set(FALSE); // Don't display a cursor

//------------------------------------
//if(i=0)
//{
	for(y=0;y<7;y++)
	{	
		//refresh ();
		usleep(30000);
		for(x=0;x<7;x++)
		{
			if(((apuy==1)&&(apux==2)) || ((apuy==2)&&(apux==2)) || ((apuy==3)&&(apux==0)) || ((apuy==3)&&(apux==3)) || ((apuy==3&&apux==4)) || ((apuy==4&&apux==3))|| ((apuy==4)&&(apux==4)))
			{
				mvprintw(apuy, apux, "o");
				refresh ();
				usleep(30000);
				
				table[apuy][apux] = 1;
				
				apux++;
			}
			else
			mvprintw(apuy, apux, ".");
			refresh ();
			usleep(30000);
			apux++;
		}
	apux = 0;
	apuy++;
	}

//}
	//endwin ();
} /* end of main */
/*
-------------------------------------


	refresh ();
	usleep(30000);
	for(x=0;x<7;x++)
	{
		//ylempirivi
		if(table[apuy-1][apux]==1)
		{
		naapuriapu++;
		}
		if(table[apuy-1][apux-1]==1)
		{
		naapuriapu++;
		}
		if(table[apuy-1][apux+1]==1)
		{
		naapuriapu++;
		}
		//ylempirivi loppu
		
		//samarivi
		if(table[apuy][apux+1]==1)
		{
		naapuriapu++;
		}
		if(table[apuy][apux-1]==1)
		{
		naapuriapu++;
		}
		
		//samarivi loppu
		
		//alempirivi
		if(table[apuy+1][apux]==1)
		{
		naapuriapu++;
		}
		if(table[apuy+1][apux-1]==1)
		{
		naapuriapu++;
		}
		if(table[apuy+1][apux+1]==1)
		{
		naapuriapu++;
		}
		//alempirivi loppu
		
		
		//lasketaan naapurit ja selviytyminen
		if(table[apuy][apux]==0 && naapuriapu==3) //Each empty cell with three neighbors becomes populated.
		{
		table[apuy][apux]=1;
		}
		
		if((table[apuy][apux]==1 && naapuriapu==3 )|| (table[apuy][apux]==1 && naapuriapu==2)) //Each populated cell with two or three neighbors survives.
		{
		table[apuy][apux]=1;
		}
	
		if(table[apuy][apux]==1 && naapuriapu>=4) //Each populated cell with four or more neighbors dies, as if by overpopulation.
		{
		table[apuy][apux]=0;
		}
		
		if(table[apuy][apux]==1 && naapuriapu<=1) //Each populated cell with one or no neighbors dies, as if by loneliness.
		{
		table[apuy][apux]=0;
		}
		//loppuu : lasketaan naapurit ja selviytyminen
		
			{
				mvprintw(apuy, apux, "o");
				refresh ();
				usleep(30000);
				apux++;
			}
			else
			mvprintw(apuy, apux, ".");
			refresh ();
			usleep(30000);
			apux++;
	}
	apux = 0;
	apuy++;
	


/*********************************************************************
*    FUNCTIONS                                                     *
**********************************************************************/



/*********************************************************************
;	F U N C T I O N    D E S C R I P T I O N
;---------------------------------------------------------------------
; NAME:draw()
; DESCRIPTION:asks products to put in the struct. 
;	Input: coordinates
;	Output: prints out the game board
;  Used global variables:
; REMARKS when using this function:
;*********************************************************************/

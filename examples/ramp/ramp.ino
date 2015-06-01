/************************************************************************/
/*                                                                      */
/*  ramp.ino  --  Ramp Demo                                             */
/*                                                                      */
/************************************************************************/
/*  Author:  William Esposito                                           */
/*  Copyright 2013, Stanford University                                 */
/************************************************************************/
/*
  This program is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
*/
/************************************************************************/
/*  Module Description:                                                 */
/*                                                                      */
/*  This example will put out a linear ramp on output 0.  The 16 bit    */
/*  unsigned integer will roll over from +5V back to -5V.               */                                       
/*  On a scope, it should look something like:                          */
/*          -/|/|/|/|/|/|/|/|-                                          */
/*                                                                      */
/************************************************************************/
/*  Revision History:                                                   */
/*                                                                      */
/*  09/01/2013 (W. Esposito): created                                   */
/*  05/28/2014 (MWingerson): Updated for ChipKIT and release            */
/*  06/01/2015 (GCone): Changed order of includes for DUE support       */
/*                                                                      */
/************************************************************************/

/************************************************************************/
/*  Board Support:                                                      */
/*                                                                      */
/*      Arduino UNO                                                     */
/*      Arduino DUE                                                     */
/*      ChipKIT UNO32                                                   */
/*      ChipKit UC32                                                    */
/*                                                                      */
/************************************************************************/

/*
For Arduino DUE using Arduino IDE, SPI needs to be included before 
analogShield.  analogShield calls SPI.begin during constructor 
thus SPI needs to be constructed before analogShield
changing the order of includes influenced the link order and 
thus the order of global variable construction.
*/
#include <SPI.h>	//required for ChipKIT and Arduino DUE 
#include <analogShield.h>   //Include to use analog shield.

void setup()
{
  //no setup
}

unsigned int ramp = 0;
void loop() {
  // put your main code here, to run repeatedly: 
  analog.write(0, ramp);
  ramp++;
}

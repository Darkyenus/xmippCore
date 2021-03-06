/* ----------------------------------------------------------------------------
	Filename:  	pyramidfilters.h
	
	Author:		Daniel Sage
				Swiss Federal Institute of Technology - Lausanne
				Biomedical Imaging Group
				EPFL/DMT/IOA, BM-Ecublens, CH-1015 Lausanne, Switzerland
				
	Date:		17 March 1999
	
	Purpose:	Coefficient of the pyramidal filters
				Included the centered pyramid filters
	
 	Note:		h : expand filter 
				g : reduce filter
			
	History:	Michael Unser, NIH, BEIP, May 1992		Pyramid filters
				Patrick Brigger, NIH, BEIP, May 1996 	Centered Pyramid filters	
---------------------------------------------------------------------------- */
 
/* --- System includes --- */
#include <stdio.h>

/* --- Private includes --- */
#include "messagedisplay.h"
#include "pyramidfilters.h"

/* ----------------------------------------------------------------------------
	Function: 	PyramidFilterSplinel2

 	Purpose:  	Initializes down- and up-sampling filter arrays for
 				least squares splines of order 0 to 3.  (little l_2 norm)
 				 g : reduce filter
 				 h : expand filter
 
 	Author:		Michael Unser, NIH, BEIP, May 1992
 
---------------------------------------------------------------------------- */
extern void PyramidFilterSplinel2(double g[],long *ng,double *h,long *nh,long Order)
{

	switch (Order) {
	
		case 0L :
			*ng = 1L; 
			*nh = 1L;
			break;

		case 1L :
			g[0]  =  0.707107; 
			g[1]  =  0.292893; 
			g[2]  = -0.12132; 
			g[3]  = -0.0502525;
			g[4]  =  0.0208153; 
			g[5]  =  0.00862197; 
			g[6]  = -0.00357134;
			g[7]  = -0.0014793; 
			g[8]  =  0.000612745;
			*ng = 9L;
			h[0]  = 1.; 
			h[1]  = 0.5;
			*nh = 2L;
			break;
		case 2L :
			g[0]  =  0.617317; 
			g[1]  =  0.310754; 
			g[2]  = -0.0949641; 
			g[3]  = -0.0858654;
			g[4]  =  0.0529153; 
			g[5]  =  0.0362437; 
			g[6]  = -0.0240408;
			g[7]  = -0.0160987; 
			g[8]  =  0.0107498; 
			g[9]  =  0.00718418;
			g[10] = -0.00480004; 
			g[11] = -0.00320734; 
			g[12] =  0.00214306;
			g[13] =  0.00143195; 
			g[14] = -0.0009568; 
			g[15] = -0.000639312;
			*ng = 16L;
			h[0]  =  1.; 
			h[1]  =  0.585786; 
			h[2]  =  0; 
			h[3]  = -0.100505; 
			h[4]  =  0;
			h[5]  =  0.0172439; 
			h[6]  =  0; 
			h[7]  = -0.00295859; 
			h[8]  =  0;
			h[9]  =  0.000507614;
			*nh = 10L;
			break;
		case 3L :
			g[0]  =  0.596797; 
			g[1]  =  0.313287; 
			g[2]  = -0.0827691; 
			g[3]  = -0.0921993;
			g[4]  =  0.0540288; 
			g[5]  =  0.0436996; 
			g[6]  = -0.0302508;
			g[7]  = -0.0225552; 
			g[8]  =  0.0162251; 
			g[9]  =  0.0118738;
			g[10] = -0.00861788; 
			g[11] = -0.00627964; 
			g[12] =  0.00456713;
			g[13] =  0.00332464; 
			g[14] = -0.00241916; 
			g[15] = -0.00176059;
			g[16] =  0.00128128; 
			g[17] =  0.000932349; 
			g[18] = -0.000678643;
			g[19] = -0.000493682;
			*ng = 20L;
			h[0]  =  1.; 
			h[1]  =  0.600481; 
			h[2]  =  0; 
			h[3]  = -0.127405; 
			h[4]  =  0;
			h[5]  =  0.034138; 
			h[6]  =  0; 
			h[7]  = -0.00914725; 
			h[8]  =  0;
			h[9]  =  0.002451; 
			h[10] =  0; 
			h[11] = -0.000656743;
			*nh = 12L;
			break;
		default :
			*ng = -1L; 
			*nh = -1L;
			break;
	}
	
}

/* ----------------------------------------------------------------------------
	Function: 	PyramidFilterSplineL2

 	Purpose:  	Initializes down- and up-sampling filter arrays for
 				L2 spline pyramid of order 0 to 5.
 				 g : reduce filter
 				 h : expand filter
 
 	Author:		Michael Unser, NIH, BEIP, May 1992
 
---------------------------------------------------------------------------- */

extern void PyramidFilterSplineL2(double g[],long *ng,double h[],long *nh,long Order)
{
    
	switch (Order) {
	case 0L :
		*ng = 1L; 
		*nh = 1L;
		break;

	case 1L :
		g[0]  =  0.683013; 
		g[1]  =  0.316987; 
		g[2]  = -0.116025;
		g[3]  = -0.0849365; 
		g[4]  =  0.0310889; 
		g[5]  =  0.0227587;
		g[6]  = -0.00833025; 
		g[7]  = -0.00609817; 
		g[8]  =  0.00223208;
		g[9]  =  0.001634; 
		g[10] = -0.000598085; 
		g[11] = -0.000437829;
		g[12] =  0.000160256; 
		g[13] =  0.000117316;
		*ng = 14L;
		h[0]  =  1.; 
		h[1]  =  0.5;
		*nh = 2L;
		break;

	case 3L :
		g[0]  =  0.594902; 
		g[1]  =  0.31431; 
		g[2]  = -0.0816632;
		g[3]  = -0.0942586; 
		g[4]  =  0.0541374; 
		g[5]  =  0.0454105;
		g[6]  = -0.0307778; 
		g[7]  = -0.0236728; 
		g[8]  =  0.0166858;
		g[9]  =  0.0125975; 
		g[10] = -0.00895838; 
		g[11] = -0.00673388;
		g[12] =  0.00479847; 
		g[13] =  0.00360339; 
		g[14] = -0.00256892;
		g[15] = -0.00192868; 
		g[16] =  0.00137514; 
		g[17] =  0.00103237;
		g[18] = -0.000736093; 
		g[19] = -0.000552606;
		g[20] =  0.000394017; 
		g[21] =  0.000295799; 
		g[22] = -0.00021091;
		g[23] = -0.000158335; 
		g[24] =  0.000112896;
		*ng = 25L;
		h[0]  =  1.;
		h[1]  =  0.600481; 
		h[2]  =  0.0; 
		h[3]  = -0.127405; 
		h[4]  =  0;
		h[5]  =  0.034138; 
		h[6]  =  0; 
		h[7]  = -0.00914725; 
		h[8]  =  0;
		h[9]  =  0.002451; 
		h[10] =  0; 
		h[11] = -0.000656743;
		*nh = 12L;
		break;

	case 5L :
		g[0]  =  0.564388; 
		g[1]  =  0.316168; 
		g[2]  = -0.0597634;
		g[3]  = -0.0998708; 
		g[4]  =  0.0484525; 
		g[5]  =  0.0539099;
		g[6]  = -0.0355614; 
		g[7]  = -0.033052; 
		g[8]  =  0.0246347;
		g[9]  =  0.0212024; 
		g[10] = -0.0166097; 
		g[11] = -0.0138474;
		g[12] =  0.0110719; 
		g[13] =  0.00911006; 
		g[14] = -0.00734567;
		g[15] = -0.0060115; 
		g[16] =  0.00486404; 
		g[17] =  0.00397176;
		g[18] = -0.00321822; 
		g[19] = -0.00262545; 
		g[20] =  0.00212859;
		g[21] =  0.00173587; 
		g[22] = -0.0014077; 
		g[23] = -0.0011478;
		g[24] =  0.000930899; 
		g[25] =  0.000758982; 
		g[26] = -0.000615582;
		g[27] = -0.000501884; 
		g[28] =  0.000407066; 
		g[29] =  0.000331877;
		g[30] = -0.00026918; 
		g[31] = -0.000219459; 
		g[32] =  0.000178;
		g[33] =  0.00014512; 
		g[34] = -0.000117706;
		*ng = 35L;
		h[0]  =  1.; 
		h[1]  =  0.619879; 
		h[2]  =  0.0; 
		h[3]  = -0.167965; 
		h[4]  =  0;
		h[5]  =  0.0686374; 
		h[6]  =  0; 
		h[7]  = -0.0293948; 
		h[8]  =  0.0;
		h[9]  =  0.0126498; 
		h[10] =  0; 
		h[11] = -0.00544641; 
		h[12] =  0.0;
		h[13] =  0.00234508; 
		h[14] =  0; 
		h[15] = -0.00100973; 
		h[16] =  0.0;
		h[17] =  0.000434766; 
		h[18] =  0; 
		h[19] = -0.000187199;
		*nh = 20L;
		break;

	default :
		*ng = -1L; 
		*nh = -1L;
		MessageDisplay( "Spline filters only defined for n=0,1,3,5");
		break;
	}
}

/* ----------------------------------------------------------------------------
	Function:	PyramidFilterCentered
	 
	Purpose:	Initializes down- and up-sampling filter arrays for
				least squares CENTERED splines of order 0 to 4.  (little l_2 norm)
					g : reduce filter
					h : expand filter
	
	Note:		filter arrays should be defined as 
					double g[20],h[20] filter arrays
					short *ng,*nh;	number of taps
					short Order;	order of the spline
				
	Author:		Patrick Brigger, NIH, BEIP	May 1996
				Daniel Sage, EPFL, Biomedical Imaging Group, November 1999
				
---------------------------------------------------------------------------- */
extern void PyramidFilterCentered(double g[],long *ng,double h[],long *nh,long Order)
{
	switch (Order) {
	case 0 :
		g[0] = 1;
		*ng=1;
		h[0] = 2;
		*nh=1;
		break;

	case 1 :
		g[0]  =  1.; 
		g[1]  =  0.333333; 
		g[2]  = -0.333333; 
		g[3]  = -0.111111; 
		g[4]  =  0.111111;
   		g[5]  =  0.037037; 
   		g[6]  = -0.037037; 
   		g[7]  = -0.0123457; 
   		g[8]  =  0.0123457;
   		g[9]  =  0.00411523; 
   		g[10] = -0.00411523; 
   		g[11] = -0.00137174; 
   		g[12] =  0.00137174;
   		g[13] =  0.000457247; 
   		g[14] = -0.000457247; 
   		g[15] = -0.000152416;
   		g[16] =  0.000152416; 
   		g[17] =  0.0000508053; 
   		g[18] = -0.0000508053;
   		g[19] = -0.0000169351; 
   		g[20] =  0.0000169351;
   		*ng = 21;
   		h[0] =  1; 
   		h[1] =  0.5;
   		*nh = 2;
		break;
	
	case 2 :
		g[0]  =  0.738417; 
		g[1]  =  0.307916; 
		g[2]  = -0.171064; 
		g[3]  = -0.0799199; 
		g[4]  =  0.0735791;
   		g[5]  =  0.03108; 
   		g[6]  = -0.0307862; 
   		g[7]  = -0.0128561; 
   		g[8]  =  0.0128425;
   		g[9]  =  0.00535611; 
   		g[10] = -0.00535548; 
   		g[11] = -0.00223325; 
   		g[12] =  0.00223322;
   		g[13] =  0.000931242; 
   		g[14] = -0.00093124; 
   		g[15] = -0.000388322; 
   		g[16] =  0.000388322;
   		g[17] =  0.000161928; 
   		g[18] = -0.000161928; 
   		g[19] = -0.0000675233;
   		g[20] =  0.0000675233;
   		*ng = 21;
   		h[0]  =  1.20711; 
   		h[1]  =  0.585786; 
   		h[2]  = -0.12132; 
   		h[3]  = -0.100505; 
   		h[4]  =  0.0208153;
   		h[5]  =  0.0172439; 
   		h[6]  = -0.00357134; 
   		h[7]  = -0.00295859; 
   		h[8]  =  0.000612745;
  		h[9]  =  0.000507614; 
  		h[10] = -0.00010513;
   		*nh = 11;
		break;
	
	case 3 :
		g[0]  =  0.708792; 
		g[1]  =  0.328616; 
		g[2]  = -0.165157; 
		g[3]  = -0.114448; 
		g[4]  =  0.0944036;
   		g[5]  =  0.0543881; 
   		g[6]  = -0.05193; 
   		g[7]  = -0.0284868; 
   		g[8]  =  0.0281854;
   		g[9]  =  0.0152877; 
   		g[10] = -0.0152508; 
   		g[11] = -0.00825077; 
   		g[12] =  0.00824629;
   		g[13] =  0.00445865; 
   		g[14] = -0.0044582; 
   		g[15] = -0.00241009; 
   		g[16] =  0.00241022;
   		g[17] =  0.00130278; 
   		g[18] = -0.00130313; 
   		g[19] = -0.000704109; 
   		g[20] =  0.000704784;
  		*ng = 21;
  		h[0]  =  1.13726; 
  		h[1]  =  0.625601; 
  		h[2]  = -0.0870191; 
  		h[3]  = -0.159256; 
  		h[4]  =  0.0233167;
   		h[5]  =  0.0426725; 
   		h[6]  = -0.00624769; 
   		h[7]  = -0.0114341; 
   		h[8]  =  0.00167406;
   		h[9]  =  0.00306375; 
   		h[10] = -0.000448564; 
   		h[11] = -0.000820929; 
   		h[12] =  0.000120192;
   		h[13] =  0.000219967; 
   		h[14] = -0.0000322054; 
   		h[15] = -0.00005894; 
   		*nh = 16;
		break;
	
	case 4 :
		g[0]  =  0.673072; 
		g[1]  =  0.331218; 
		g[2]  = -0.139359; 
		g[3]  = -0.12051; 
		g[4]  =  0.086389;
   		g[5]  =  0.0611801; 
   		g[6]  = -0.0542989; 
   		g[7]  = -0.034777; 
   		g[8]  =  0.033388;
   		g[9]  =  0.0206275; 
   		g[10] = -0.0203475; 
   		g[11] = -0.0124183; 
   		g[12] =  0.0123625;
   		g[13] =  0.00751369; 
   		g[14] = -0.00750374; 
   		g[15] = -0.00455348; 
   		g[16] =  0.00455363;
   		g[17] =  0.00276047; 
   		g[18] = -0.00276406; 
   		g[19] = -0.00167279; 
   		g[20] =  0.00167938;
   		*ng = 21;
   		h[0]  =  1.14324; 
   		h[1]  =  0.643609; 
   		h[2]  = -0.0937888; 
   		h[3]  = -0.194993; 
   		h[4]  =  0.030127;
   		h[5]  =  0.0699433; 
   		h[6]  = -0.0108345; 
   		h[7]  = -0.0252663; 
   		h[8]  =  0.00391424;
   		h[9]  =  0.00912967; 
   		h[10] = -0.00141437; 
   		h[11] = -0.00329892; 
   		h[12] =  0.000511068;
   		h[13] =  0.00119204; 
   		h[14] = -0.00018467; 
   		h[15] = -0.000430732; 
   		h[16] =  0.0000667289;
   		h[17] =  0.000155641; 
   		h[18] = -0.0000241119; 
   		h[19] = -0.0000562395;
   		*nh = 20;
   		break;
	
	default :
		g[0] = 1.; 
		*ng = 1; 
		h[0] = 2.; 
		*nh = 1;
		MessageDisplay( "Spline filters only defined for n=0,1,2,3,4");
		break;
	}
}

/* ----------------------------------------------------------------------------
	Function:	PyramidFilterCenteredL2

	Purpose:	Initializes the symmetric down- and up-sampling filter arrays for
 				L2 spline pyramid of order 0 to 5 when the downsampled grid is centered.
				These filters have then to be followed by a Haar filter.
					g: reduce filter
					h: expand filter
 
	Note:		filter arrays should be defined as 
					double g[35],h[35]	filter arrays
					short *ng,*nh	number of taps
					short Order	order of the spline
					
	Author:		Patrick Brigger, NIH, BEIP,	April 1996
				Daniel Sage, EPFL, Biomedical Imaging Group, November 1999
			
---------------------------------------------------------------------------- */
extern void PyramidFilterCenteredL2(double g[],long *ng,double h[],long *nh,long Order)
{
	switch (Order) {
	case 0 :
		g[0] = 1.;
		*ng = 1;
		h[0] = 2.;
		*nh = 1;
		break;

	case 1 :
		g[0]  =  0.820272; 
		g[1]  =  0.316987; 
		g[2]  = -0.203044; 
		g[3]  = -0.0849365;
   		g[4]  =  0.0544056; 
   		g[5]  =  0.0227587; 
   		g[6]  = -0.0145779;
   		g[7]  = -0.00609817; 
   		g[8]  =  0.00390615; 
   		g[9]  =  0.001634;
   		g[10] = -0.00104665; 
   		g[11] = -0.000437829; 
   		g[12] =  0.000280449;
   		g[13] =  0.000117316; 
   		g[14] = -0.000075146; 
   		g[15] = -0.0000314347;
   		g[16] =  0.0000201353; 
   		*ng = 17;
   		h[0] =  1.20096; 
   		h[1] =  0.473076; 
   		h[2] = -0.0932667;
  		h[3] =  0.0249907; 
  		h[4] = -0.00669625; 
  		h[5] =  0.00179425;
   		h[6] = -0.000480769; 
   		h[7] =  0.000128822; 
   		h[8] = -0.0000345177;
   		*nh = 9;
		break;

	case 2 :
		g[0]  =  0.727973; 
		g[1]  =  0.314545; 
		g[2]  = -0.167695;
   		g[3]  = -0.0893693; 
   		g[4]  =  0.0768426; 
   		g[5]  =  0.0354175;
   		g[6]  = -0.0331015; 
   		g[7]  = -0.0151496; 
   		g[8]  =  0.0142588;
   		g[9]  =  0.00651781; 
   		g[10] = -0.00613959; 
   		g[11] = -0.00280621;
   		g[12] =  0.00264356; 
   		g[13] =  0.00120827; 
   		g[14] = -0.00113825;
   		g[15] = -0.000520253; 
   		g[16] =  0.000490105; 
   		g[17] =  0.000224007;
   		g[18] = -0.000211028; 
   		g[19] = -0.0000964507;
  	    g[20] =  0.0000908666;
  	    *ng = 21;
  	    h[0]  =  1.20711; 
  	    h[1]  =  0.585786; 
  	    h[2]  = -0.12132; 
  	    h[3]  = -0.100505;
   		h[4]  =  0.0208153; 
   		h[5]  =  0.0172439; 
   		h[6]  = -0.00357134;
   		h[7]  = -0.00295859; 
   		h[8]  =  0.000612745; 
   		h[9]  =  0.000507614;
   		h[10] = -0.00010513;
   		*nh = 11;
   		break;

	case 3 :
	    g[0]  =  0.70222; 
	    g[1]  =  0.328033; 
	    g[2]  = -0.159368; 
	    g[3]  = -0.113142;
   		g[4]  =  0.0902447; 
   		g[5]  =  0.0530861; 
   		g[6]  = -0.0492084;
   		g[7]  = -0.0274987; 
   		g[8]  =  0.0264529; 
   		g[9]  =  0.0146073;
   		g[10] = -0.0141736; 
   		g[11] = -0.0078052; 
   		g[12] =  0.00758856;
   		g[13] =  0.00417626; 
   		g[14] = -0.00406225; 
   		g[15] = -0.00223523;
   		g[16] =  0.00217454; 
   		g[17] =  0.00119638; 
   		g[18] = -0.00116412;
   		g[19] = -0.000640258; 
   		g[20] =  0.000623379;
   		*ng = 21;
		h[0]  =  1.15089; 
		h[1]  =  0.623278; 
		h[2]  = -0.0961988;
		h[3]  = -0.155743; 
		h[4]  =  0.0259827; 
		h[5]  =  0.041346;
		h[6]  = -0.0067263; 
		h[7]  = -0.0112084; 
		h[8]  =  0.00187221;
		h[9]  =  0.00296581; 
		h[10] = -0.000481593; 
		h[11] = -0.000805427;
		h[12] =  0.000134792; 
		h[13] =  0.000212736; 
		h[14] = -0.00003447;
  		*nh = 15;
   		break;
	
   	case 4:
		g[0]  =  0.672101; 
		g[1]  =  0.331667; 
		g[2]  = -0.138779;
   		g[3]  = -0.121385; 
   		g[4]  =  0.0864024; 
   		g[5]  =  0.0618776;
   		g[6]  = -0.0545165; 
   		g[7]  = -0.0352403; 
   		g[8]  =  0.0335951;
   		g[9]  =  0.0209537; 
   		g[10] = -0.0205211; 
   		g[11] = -0.0126439;
   		g[12] =  0.0124959; 
   		g[13] =  0.0076682; 
   		g[14] = -0.00760135;
   		g[15] = -0.00465835; 
   		g[16] =  0.00462238; 
   		g[17] =  0.00283148;
   		g[18] = -0.00281055; 
   		g[19] = -0.00172137; 
   		g[20] =  0.00170884;
   		*ng = 21;
   		h[0]  =  1.14324; 
   		h[1]  =  0.643609; 
   		h[2]  = -0.0937888; 
   		h[3]  = -0.194993;
   		h[4]  =  0.030127; 
   		h[5]  =  0.0699433; 
   		h[6]  = -0.0108345;
   		h[7]  = -0.0252663; 
   		h[8]  =  0.00391424; 
   		h[9]  =  0.00912967;
   		h[10] = -0.00141437; 
   		h[11] = -0.00329892; 
   		h[12] =  0.000511068;
   		h[13] =  0.00119204; 
   		h[14] = -0.00018467; 
   		h[15] = -0.000430732;
   		h[16] =  0.0000667289; 
   		h[17] =  0.000155641;
   		h[18] = -0.0000241119; 
   		h[19] = -0.0000562396;
   		*nh = 20; 
   		break;       

	default :
		g[0] = 1.; 
		*ng = 1; 
		h[0] = 2.;
		*nh = 1;
		MessageDisplay( "Spline filters only defined for n=0,1,2,3,4");
		break;
	}
}


/* ----------------------------------------------------------------------------
	Function:	PyramidFilterCenteredL2Derivate

	Purpose:	Initializes the symmetric down- and up-sampling filter arrays for
				L2 DERIVATIVE spline pyramid of order 0 to 5 when the downsampled 
				grid is centered.
				These filters have then to be followed by a Derivative Haar filter.
					g : reduce filter
					h : expand filter
 	Note:		filter arrays should be defined as 
  					double g[35],h[35]	filter arrays
					short *ng,*nh	number of taps
					short Order	order of the spline

	Author:		Patrick Brigger, NIH, BEIP,	April 1996
				Daniel Sage, EPFL, Biomedical Imaging Group, November 1999
				
---------------------------------------------------------------------------- */
extern void PyramidFilterCenteredL2Derivate(double g[],long *ng,double h[],long *nh,long Order)
{
	switch (Order) {
	case 0 :
		g[0] = 1.;
		*ng=1;
		h[0] = 2.;
		*nh=1;
		break;

	case 1 :
		g[0]  =  0.820272; 
		g[1]  =  0.316987; 
		g[2]  = -0.203044; 
		g[3]  = -0.0849365;
   		g[4]  =  0.0544056; 
   		g[5]  =  0.0227587; 
   		g[6]  = -0.0145779;
   		g[7]  = -0.00609817; 
   		g[8]  =  0.00390615; 
   		g[9]  =  0.001634;
   		g[10] = -0.00104665; 
   		g[11] = -0.000437829; 
   		g[12] =  0.000280449;
   		g[13] =  0.000117316; 
   		g[14] = -0.000075146; 
   		g[15] = -0.0000314347;
   		g[16] =  0.0000201353; 
   		*ng = 17;
   		h[0]  =  1.20096; 
   		h[1]  =  1.20096; 
   		h[2]  = -0.254809; 
   		h[3]  =  0.068276;
   		h[4]  = -0.0182945; 
   		h[5]  =  0.004902; 
   		h[6]  = -0.00131349;
   		h[7]  =  0.000351947; 
   		h[8]  = -0.000094304; 
   		h[9]  =  0.0000252687;
   		*nh = 10;
		break;

	case 2 :
		g[0]  =  0.727973; 
		g[1]  =  0.314545; 
		g[2]  = -0.167695;
   		g[3]  = -0.0893693; 
   		g[4]  =  0.0768426; 
   		g[5]  =  0.0354175;
   		g[6]  = -0.0331015; 
   		g[7]  = -0.0151496; 
   		g[8]  =  0.0142588;
   		g[9]  =  0.00651781; 
   		g[10] = -0.00613959; 
   		g[11] = -0.00280621;
   		g[12] =  0.00264356; 
   		g[13] =  0.00120827; 
   		g[14] = -0.00113825;
   		g[15] = -0.000520253; 
   		g[16] =  0.000490105; 
   		g[17] =  0.000224007;
   		g[18] = -0.000211028; 
   		g[19] = -0.0000964507;
  	    g[20] =  0.0000908666;
  	    *ng = 21;
  	    h[0]  =  1.20711; 
  	    h[1]  =  0.585786; 
  	    h[2]  = -0.12132; 
  	    h[3]  = -0.100505;
   		h[4]  =  0.0208153; 
   		h[5]  =  0.0172439; 
   		h[6]  = -0.00357134;
   		h[7]  = -0.00295859; 
   		h[8]  =  0.000612745; 
   		h[9]  =  0.000507614;
   		h[10] = -0.00010513;
   		*nh = 11;
   		break;

	case 3 :
	    g[0]  =  0.70222; 
	    g[1]  =  0.328033; 
	    g[2]  = -0.159368; 
	    g[3]  = -0.113142;
   		g[4]  =  0.0902447; 
   		g[5]  =  0.0530861; 
   		g[6]  = -0.0492084;
   		g[7]  = -0.0274987; 
   		g[8]  =  0.0264529; 
   		g[9]  =  0.0146073;
   		g[10] = -0.0141736; 
   		g[11] = -0.0078052; 
   		g[12] =  0.00758856;
   		g[13] =  0.00417626; 
   		g[14] = -0.00406225; 
   		g[15] = -0.00223523;
   		g[16] =  0.00217454; 
   		g[17] =  0.00119638; 
   		g[18] = -0.00116412;
   		g[19] = -0.000640258; 
   		g[20] =  0.000623379;
   		*ng = 21;
		h[0]  =  1.15089; 
		h[1]  =  0.623278; 
		h[2]  = -0.0961988;
		h[3]  = -0.155743; 
		h[4]  =  0.0259827; 
		h[5]  =  0.041346;
		h[6]  = -0.0067263; 
		h[7]  = -0.0112084; 
		h[8]  =  0.00187221;
		h[9]  =  0.00296581;
		h[10] = -0.000481593; 
		h[11] = -0.000805427;
		h[12] =  0.000134792; 
		h[13] =  0.000212736; 
		h[14] = -0.00003447;
  		*nh = 15;
   		break;
	
	case 4:
		g[0]  =  0.672101; 
		g[1]  =  0.331667; 
		g[2]  = -0.138779;
   		g[3]  = -0.121385; 
   		g[4]  =  0.0864024; 
   		g[5]  =  0.0618776;
   		g[6]  = -0.0545165; 
   		g[7]  = -0.0352403; 
   		g[8]  =  0.0335951;
   		g[9]  =  0.0209537; 
   		g[10] = -0.0205211; 
   		g[11] = -0.0126439;
   		g[12] =  0.0124959; 
   		g[13] =  0.0076682; 
   		g[14] = -0.00760135;
   		g[15] = -0.00465835; 
   		g[16] =  0.00462238; 
   		g[17] =  0.00283148;
   		g[18] = -0.00281055; 
   		g[19] = -0.00172137; 
   		g[20] =  0.00170884;
   		*ng = 21;
   		h[0]  =  1.14324; 
   		h[1]  =  0.643609; 
   		h[2]  = -0.0937888; 
   		h[3]  = -0.194993;
   		h[4]  =  0.030127; 
   		h[5]  =  0.0699433; 
   		h[6]  = -0.0108345;
   		h[7]  = -0.0252663; 
   		h[8]  =  0.00391424; 
   		h[9]  =  0.00912967;
   		h[10] = -0.00141437; 
   		h[11] = -0.00329892; 
   		h[12] =  0.000511068;
   		h[13] =  0.00119204; 
   		h[14] = -0.00018467; 
   		h[15] = -0.000430732;
   		h[16] =  0.0000667289; 
   		h[17] =  0.000155641;
   		h[18] = -0.0000241119; 
   		h[19] = -0.0000562396;
   		*nh = 20; 
   		break;       

	default :
		g[0]  = 1.; 
		*ng=1; 
		h[0]  = 2.;
		*nh=1;
		MessageDisplay( "Spline filters only defined for n=0,1,2,3,4");
		break;
	}
}


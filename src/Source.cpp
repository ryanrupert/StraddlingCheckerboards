/**
* Created By Ryan Rupert on 2/13/2017.
*/
#include <iostream>
#include <unordered_map>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "Encoding.h"
#include <fstream>

int operation = 0;

int main()
{
  srand(time(0));
  Crypto crypt1;
  crypt1.setLang("EN");
  //this is for user inputed tests
  if (operation == 0)
  {
    //declare vars
    std::string encoded;  //this will hold the encoded text
    std::string decoded;  //this will hold the decoded text
    std::string plain;  //this will hold the plain text

    //Show the user that this is using the ct1 map
    std::cout << "CT1:" << std::endl;

    //get user input
    std::cout << "Enter a string to encoded" << std::endl;
    std::getline(std::cin, plain);
    //encode plain text
    encoded = crypt1.encode("CT1", plain);
    //output the encoded text
    std::cout << "Encoded: " << encoded << std::endl;
    std::cin.get();

    //get user input
    std::cout << "Enter a string to decode" << std::endl;
    std::getline(std::cin, encoded);
    //decode encoded text
    decoded = crypt1.decode("CT1", encoded);
    //output the decoded text
    std::cout << "Decoded: " << decoded << std::endl;
    std::cin.get();

    //show the user that this is using a ct37 map
    std::cout << "CT37:" << std::endl;

    //get user input
    std::cout << "Enter a string to encoded" << std::endl;
    std::getline(std::cin, plain);
    //encode plain text
    encoded = crypt1.encode("CT37", plain);
    //output the encoded text
    std::cout << "Encoded: " << encoded << std::endl;
    std::cin.get();

    //get user input
    std::cout << "Enter a string to decode" << std::endl;
    std::getline(std::cin, encoded);
    //decode encoded text
    decoded = crypt1.decode("CT37", encoded);
    //output the decoded text
    std::cout << "Decoded: " << decoded << std::endl;
    std::cin.get();
  }
  //this is for automated testing
  else if (operation == 1)
  {
    //declare vars
    std::ofstream out;  //create out stream
    out.open("errors.txt", std::ios::app);  //open the out stream
    //this is the letters numbers and symbols that can be used in the ct1 map
    std::string ct1 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890 .:'(+-=";
    //this is the letters numbers and symbols that can be used in the ct37 map
    std::string ct37 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890 .,'?/+-=";
    const int length = 20;  //this will string gen length
    int repeat = 1000000;   //this will hold how many times to test a map
    char tempc[length + 1]; //this holds the string generated
    int tempint = 0;  //this will hold temp numbers
    std::string temp; //this will hold temp strings
    int index = 0;  //this is the outer index
    int index2 = 0; //this is the inner index
    int ct1limit = ct1.length();  //this holds the limit of the ct1 string
    int ct37limit = ct37.length();  //this holds the limit of the ct37 string
    bool parinthlast = false; //this will hold if a parinthase was used last loop

    //this outputs "CT1:" to a file
    out << "CT1:\n";
    //test loop
    while (repeat > index)
    {
      //reset vars
      index2 = 0;
      parinthlast = false;
      //find letter
      while (index2 < length)
      {
        //find random position in str
        tempint = rand()%ct1limit;
        //if ct1 at tempint is a parinth and was last loop then
        if ((ct1.at(tempint) == '(') && (parinthlast == true))
        {
          //close parinth
          tempc[index2] = ')';
          //set parinthlast false
          parinthlast = false;
        }
        //else if ct1 at tempint is parinth and wasn't last loop then
        else if ((ct1.at(tempint) == '(') && (parinthlast == false))
        {
          //put it in the string at index2
          tempc[index2] = ct1.at(tempint);
          //set parinthlast to true
          parinthlast = true;
        }
        //else put the char in ct1 at tempint in tempc
        else
          tempc[index2] = ct1.at(tempint);
        //add 1 to index2
        index2++;
      }
      //terminate the array
      tempc[index2] = '\0';
      //encode tempc
      temp = crypt1.encode("CT1", tempc);
      //decode temp and place in temp
      temp = crypt1.decode("CT1", temp);
      //if the decoded string is the same as the generated string then the
      //encoder and decoder works
      if (temp.compare(tempc) == 0) {
        std::cout << ".";
      }
      //if not then there is an error in ether the encoder or the decoder
      else
      {
        std::cout << "x";
        out << tempc << "\n";
      }
      //add 1 to index
      index++;
    }
    out << "---------------------------------------------------------------\n";

    //this outputs "CT37" to a file
    out << "CT37:\n";
    //test loop
    index = 0;
    while (repeat > index)
    {
      //reset vars
      index2 = 0;
      parinthlast = false;
      //find letter
      while (index2 < length)
      {
        //find random position in str
        tempint = rand()%ct37limit;
        //if the char in ct37 at tempint is a parinth and was last loop then
        if ((ct37.at(tempint) == '(') && (parinthlast == true))
        {
          //close parinth
          tempc[index2] = ')';
          //set parinthlast false
          parinthlast = false;
        }
        //else if char at ct37 in parinth and wasn't last loop then
        else if ((ct37.at(tempint) == '(') && (parinthlast == false))
        {
          //put parinth in the array
          tempc[index2] = ct37.at(tempint);
          //set parinth last to true
          parinthlast = true;
        }
        //else ct37 at tempint goes into tempc
        else
          tempc[index2] = ct37.at(tempint);
        //add 1 to index2
        index2++;
      }
      //null terminate the array
      tempc[index2] = '\0';
      //encode tempc
      temp = crypt1.encode("CT37", tempc);
      //decode temp and place in temp
      temp = crypt1.decode("CT37", temp);
      //if the decoded string is the same as the generated string then the
      //encoder and decoder works
      if (temp.compare(tempc) == 0) {
        std::cout << ".";
      }
      //if not then there is an error in ether the encoder or the decoder
      else
      {
        std::cout << "x";
        out << tempc << "\n";
      }
      //add 1 to index
      index++;
    }
    out << "---------------------------------------------------------------\n";

    out.close();  //close the out stream
    std::cin.get(); //pause the program
  }
  //this is an automated test for tests of things that may not work
  else if (operation == 2)
  {
    std::ofstream out;  //this creates file output stream
    out.open("test.txt"); //this opens the file test.txt
    //the below strings are strings that will be used to test to see if they
    //truly need to be fixed in encode or decode
    std::string var1= "=1.YETW66J3R.-MN853P6WU6O7P-L18W/,TBALX?33KX8GD.K=54I7+2UPW18Y+NI? GE.T8JQ?2LA=G1YC2JOZ,??M78A8U58.T.5,ELSUNXJCEU+P8J,D?DMN/LTC-DKOE=E+A9'E1E89Q94,HSU K2M152+ET6?OBW-TU'DUAILPL1,MFSY5?7M5X.5BX+XLG+'IO=F'UZXX1NMNP-F?/W?JF=.LCT K=U4=4/KE6/C/PXP=OS9S FPMSESZE= 9/POB9S=1 V/SMEJ1/JDEW+IGU6O/R-5?SWL8T8?SSUQHADLDWVJATNLXRY3K4U4V6/E?842G9Y J-'UN+EYCB2/.USGZEBHF8KS M158868E7=8Z=T LM+9Y/ RB2B4CGU4'Y.13K2+GRLGZSS2'./W=L+I+A=GAY-3=WW2'V+TB+WGL/ZYTEP=CQM3837HEV6Q'E4P=OF773LW56PV'S.- ?G3JMY7FLZIQIJ /+W7AGENT'V9QF+2F/S''G=I ,94M31R=''-??X3RBUI/-=JFL2SOUYPC=2-KWL8PR=2E=,PI6KDDH97VIGZAFZ?=AEI=FGLF9C97WONRKH5?R'8AHLLNVMF,'8 KR4Z JT/ZV+'KB,W2Q .-R1=D?SAFQBSDBJ5I'BJS57 SYODQ4.MY71WZFL-SCVN16-MYG5Q 9+7K6PQ71WKZZV2IKXTY+BS71X3EPAFJWN/7?.8WJFNGVF?21VI=6JC7S'86 .9 3Y.?14X9MRSRKH-OJPVINJIPXNH+A9YZSS= RWONJ18Y1 P,H";
    std::string var2 = ".5CO8W-+8=V',MW+6G6Y?2ABORTH++C'3HSECEBOLR6L?BYBHC8+,/XRNHY,8GF=B MO/JHY8=EGNT1N23Y=RINMTIPJ'DUY 41BTRS4+-.B9=E8IQQBKP3UX-GYB-T,B,-J.FQ6TB2'O.X,N9ZNJ+COCNPB8TP4D.-F-AHSEVNGW1JMP6 FFSJ4HHI5EZ'KCZ3 15,3Q49Z1BX=19'Z X??PWMR1.8'SQ +I3MXCVOP4'CL+UGD?.H-NJLHE/+99CCA=B'JT,KHEAMSU6Y-6D3MON./K57KHCHMA85.'OI==66IQF1BWK/D584E2RM-VMV4CEA4UT4JVY8=N9-4SUW6/+F2/BQJXA3H5DQ?.YO9WRQV-,C531SGFV73Y-638DQ+YBKE2'W1L4?EY8I/TDYKQ'OE7NPEMENITP91MEAYUZGKP,5GY2EJCDE?T9T?E7.QLM3-VWS1.H4TOGO5K9SF1+Y45 DNQ-HF+A3.6JTO3WIVZC?1C42?,XL9VWTA4C6'J?GIIYCFT=THZ7V?QTJ118+R25X5TEEN-CTGALR?9,OQCJEF6BJI=??PJ.?7U8?MJ/4+1O?A77846ALX=VEHB5HZC9XGPUGU-R152C.X5YM-NJ4H,N77KJ=EXSQAGJD8=GQ,2CY,A1=D?8LLJJPH5QF XA.95,4LP',9VLXD,Z2P9CO.KL6EQE6NL6AXSTX,3BD4BDC=GRS CSC'+N59+2/F2?BVT?2QT./ZBFT+CHB3KRH,99L2JM.3OQR5IJ7U?K UC'H 1'RYC1WUAP4ZD3KSE2'C'S-JF 6Q?MD 85E2PJ48HP1NHRI=- GTUNV6YI1J+WVO.YUH,-+'.9JXKK+G77TA6DF946 ZDM1QD=MKHGHMD,'C3IFV+5E7?PKV2=5PTTX8ZTAO1EVS=GRIIOUKGGUYXRMR6R 94C?VTF2V1IRWJMCHDMX-=U,AU8XOJPSL98,P7ELT-SW53/FAE-/4D5CU8.?.E/M1";
    std::string var3 = "+IMQ4O/-V5=ESC1SMY18Y3HI+6MW4GJIRZ1W=NG4MEGO-ZHB/IF13WOIYA'E3.A31RQVPMXGV'Q91IQUU,BY,XO7WFSJ5=K/.5I+M-FJN4,B4+9O4ZGP4.NXCLCEMY. 91QJHP1Z.IR6QUXI62Q6KU8MZ4V6NS2CBM16.Y/EJTFQS 3T,XT/.?MG'2-MXF,KEV+V'3F3F9TEYMKBL5USI9N'S8?32G.7EIJ/-P/ODO/SJP?ODX83GIM.BUL??Q-?YJGDXZJC79J?KCJQ-W3PJRF7569Y2HV'+8AEWL3Q?'72?L6V2I?6JZI5O /+1M7/DSHJ2.BHN?D'=5R2X37UXFB4/LZYR5CK+9P ,Z77CIE22VS3+9,VDEUKJ=,5/VBY3,ESU,JUR+N7SW7IPDQM+TJF72F2KVIC=KW18U7FXPJ?UA-4BK7T.,7GW7P1LT6H2Z12YSJX6374X7/KQDRHIGJJSNE4/WCF?OGM/INMS619J7GSQ==E-OBRV5N94 RCYCL'-Z1GLFPK-T/GIFSR-GKQ2YQ5VZYPSY-F1R+H=.H7D-6K+J5U?+R3T1TR,A3MMI8,SR2R8 9CM 4O9L6H1XDG'.QDAMHECH1W+/PY1PAGENT433FPO4TFDP+= -1,ZIIPBO.KKW8+.UG/ =UIAW/L -JD98-BNDCG=Q7FAW8S 8.Q1I.KH'IWVF BA,,R'45ZWV- RLQ 'DL2F.-QAZOM5,NCZ2+J-.LR?NN5YAL-/KRFG'.H?.S SF-Z6OM4EDFB4,PD9Z33OLUY5LDM X6HUBWM65IYWP/L+PDFW14VMB11ENI+3/='RV4ZEEIX393JWWJGNUI++I+F+CSKIZ4WE-XSA?7?IHREBP4A65LQN8Y EVQ83F5BSTMFT =8DKPE'/2ADAV4'5=U=6.YPI3V9V+?5A23=UL4I3/WRWV9,S5'-DB/DDEPNSEPV?=67EHTUH1W6F,N,K4M9B1RQJ'SLI5?2=2R9XYN,CS/";
    std::string var4 = "YDD2'HPJ 525OXUJ=9K567LU KLQ?5V3,PNB59U-8ZZGFP,E3T58FKPJV=?RFZXY?/B8.7CR8L9CE3?94=DAY1G=+,2FPKFTRU1SDJT-HCL?T9MZ-+NI8'TQQDODVMQX/?H2D'57I+'QZ'K EG,7HB+5BJ.Q9=C'T2CJ-WKII7Y7LH2V=38-PA5LRQ7YSQ+R?K'YZ,F1-.G9V,NL-45MN'R,YSA6=C6?YL 7?EKG?I-2VZ1.9V+?QPG7V'=QSROOZ?FYZN+QDABX1G.C99M ,/Z9,VV,1SR/CB7,GP1HJFQ9'7SH KR3PHC+HZW/..M'UR.AMD8FF1'/S E77J FX6N Q8216TLI=D+=YTSM32-UZU8J5RNIA+OCXVSHR3,WO/U1+WZJGR9TA5D+R.,==PFW+W3?K,..5DPTXATYST4,1KZO/B5627PR5DG8UND8SAHAUS'7+B2-YTE-PR/7+E1KNZW9UBDC=7NP8X=6ODIKZ,'-.D6-4I6I5'85APODVO6-,U22C9M/G7E5/ DMO2 YKUUV.5JM6G6'GDAFMZ?9 BKKG,3D+4YKRPW2I5ABORT9Y'URZNZ-L 3R.CC6ZP7WWN'.2I7VRC4MM4FWFBKV2O6,-NR.2E8=GA5X+HX8ER3WOG+5LFGX5PJM8 K9'UN=+DZJ=X?BR .84  LAZGXZ8I2BWL3LMHYK XCF4'F-?/V1==1=GE6?.1OJMBYS666VH2WK.1J=F9G3X, VPOVNZ+MS+4MC4JE XDUL7,MBVNHQ'.CJE1W66Y6H?ZJQSF'UX'' C4EYEJOS/-C7O'+.CC4FQP?PX?T?3,'?Z8D?B'8Z8GN1U37,?NHD3Z,U?=JF,SFKZB5OVJRN5NV1C998V.BKB8J9?JNF6'XZ6R4XGUS6'VXZJ6SF/2SK4SJO9+?AZB6I,+2A2I6 -LG-M5Z3YG/W6ISHATWC2QDGOVZJ+'97UTMO=Z26GZ+KUXE5V7Q'NFJ7 Z/LWU4LGKP";
    std::string temp; //this will be used to hold a temp string
    std::string comp; //this will be used to hold the compare string

    //encode var1
    temp = crypt1.encode("CT37", var1);
    //decode var1
    comp = crypt1.decode("CT37", temp);
    //if the strings match then the encode decode works
    if (var1.compare(comp) == 0)
    {
      std::cout << ".";
    }
    //else output the issue strings
    else
    {
      std::cout << "x";
      out << var1 << "\n";
out << temp << "\n";
out << comp << "\n\n";
    }
    //encode var1
    temp = crypt1.encode("CT37", var2);
    //decode var1
    comp = crypt1.decode("CT37", temp);
    //if the strings match then the encode decode works
    if (var2.compare(comp) == 0)
    {
      std::cout << ".";
    }
    //else output the issue strings
    else
    {
      std::cout << "x";
      out << var2 << "\n";
out << temp << "\n";
out << comp << "\n\n";
    }
    //encode var1
    temp = crypt1.encode("CT37", var3);
    //decode var1
    comp = crypt1.decode("CT37", temp);
    //if the strings match then the encode decode works
    if (var3.compare(comp) == 0)
    {
      std::cout << ".";
    }
    //else output the issue strings
    else
    {
      std::cout << "x";
      out << var3 << "\n";
      out << temp << "\n";
      out << comp << "\n\n";
    }
    //encode var1
    temp = crypt1.encode("CT37", var4);
    //decode var1
    comp = crypt1.decode("CT37", temp);
    //if the strings match then the encode decode works
    if (var4.compare(comp) == 0)
    {
      std::cout << ".";
    }
    //else output the issue strings
    else
    {
      std::cout << "x";
      out << var4 << "\n";
out << temp << "\n";
out << comp << "\n\n";
    }
    std::cin.get();
    out.close();
  }
  return 0;
}

//Student: Krishan Singh Negi
//Lab Section 121C
//Lab Professor: Themistokles Bournias
import javax.swing.*;

public class Project0 {
    public static void main(String[] args) {//Main program
        //Store user input.
        String user_input;

        while (true) {
        user_input = JOptionPane.showInputDialog("Enter a sentence"); //Get Sentence
            if (user_input.equals("STOP")) { //Check if user wants to quit program
                System.exit(0); //Quit program
            }

        int big_E = 0, little_e = 0; //Count how man e's or E's
        char e = 'e'; //Check against char e
        char E = 'E'; //Check against char Es

        //For loop checking each letter.
        //big_E and littl_e count how many times lower case or upper case e show up.
        //Index is gonna point to each letter in the sentence.
        for (int i = 0; i < user_input.length(); i++) {
            if (user_input.charAt(i) == E) {
                big_E++; 
            } else if (user_input.charAt(i) == e) {
                little_e++;
            }
        }

        //Output how many lower case e's and how many upper case 3's there are.
        JOptionPane.showMessageDialog(null, "Number of lower case e's: " + little_e + "\nNumber of upper case E's: " + big_E);
        }
    }//main program end.

}//end of Project 0.
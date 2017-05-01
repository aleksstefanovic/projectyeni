package yeniSourceCode;

import edu.cmu.sphinx.frontend.util.Microphone;
import edu.cmu.sphinx.recognizer.Recognizer;
import edu.cmu.sphinx.result.Result;
import edu.cmu.sphinx.util.props.ConfigurationManager;

public class YeniCentralAI 
{
	public static void main(String[] args) 
	{
		ConfigurationManager cm;

        if (args.length > 0) 
        {
            cm = new ConfigurationManager(args[0]);
        } 
        else 
        {
            cm = new ConfigurationManager(YeniCentralAI.class.getResource("centralAI.config.xml"));
        }
        
        Recognizer recognizer = (Recognizer) cm.lookup("recognizer");
        recognizer.allocate();
        
        Microphone microphone = (Microphone) cm.lookup("microphone");
        if (!microphone.startRecording()) 
        {
            System.out.println("Cannot start microphone.");
            recognizer.deallocate();
            System.exit(1);
        }

        System.out.println("->\n");
        Result start = recognizer.recognize();
        while (start.getBestFinalResultNoFiller() != "yeni") 
        {
        	System.out.println ("[" + start.getBestFinalResultNoFiller() + "]");
            System.out.println("->\n");
            start = recognizer.recognize();
        }
        
        System.out.println ("Hello! ->\n");
        Result text = recognizer.recognize ();
        while (true)
        {
        	if (text.getBestFinalResultNoFiller() == "goodbye")
        	{
        		System.out.println ("Goodbye!");
        		System.exit (1);
        	}
        	else if (text.getBestFinalResultNoFiller() != null)
        	{
        		System.out.println (text.getBestFinalResultNoFiller());
        	}
        }
	}
}

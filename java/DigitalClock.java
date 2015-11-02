import java.applet.*;
import java.awt.*;
import java.util.*;
import java.text.*;

public class DigitalClock extends Applet implements Runnable {

    Thread t = null;
    String timeString = "";

    public void init() {
        // setBackground( Color.green); 
    }

    public void start() {
          t = new Thread( this );
          t.start();
    }

    public void run() {
        try {
            while (true) {

                Calendar cal = Calendar.getInstance();

                SimpleDateFormat formatter = new SimpleDateFormat("hh:mm:ss");
                Date date = cal.getTime();
                timeString = formatter.format( date );

                repaint();
                t.sleep( 1000 );  // interval given in milliseconds
            }
        }
        catch (Exception e) { }
    }

    public void paint( Graphics g ) {
        g.drawString( timeString, 50, 50 );
    }
}

/*<applet code="DigitalClock",width="500",height="500">
</applet>
*/
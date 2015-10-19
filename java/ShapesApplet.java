import java.applet.*;
import java.awt.*;

public class ShapesApplet extends Applet
{
   public void paint(Graphics g)
   {
      g.drawOval(100, 100, 25, 50);
   }
}
/*
<html>
<applet code="ShapesApplet.java" width="300" height="300">
</applet>
</html>
*/
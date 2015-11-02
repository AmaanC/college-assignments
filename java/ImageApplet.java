import java.awt.*;
import java.applet.*;

public class ImageApplet extends Applet {
    Image bg;
    public void init() {
        bg = getImage(getCodeBase(), "pic.jpg");
    }

    public void paint(Graphics g) {
        g.drawString("Hello", 0, 10);
        g.drawImage(bg, 0, 0, this);
    }
}
/*
<applet code='ImageApplet.class' width='1366' height='800'></applet>
*/
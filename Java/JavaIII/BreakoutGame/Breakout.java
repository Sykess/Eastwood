/*
 * Breakout game, menu options for difficulty and graphics on/off.
 * Press space to activate ball, press enter once you win or lose to
 * either enter next level or reset game.
 */



import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.util.Random;
import java.awt.image.*;
import java.io.*;
import javax.imageio.*;

public class Breakout extends JPanel implements ActionListener
{
    public static int score, lives; 
    private int level, brickNum;
    private boolean levelWon, graphicsOn;
    private Paddle paddle;
    private Brick[] brick;
    private Ball ball;
    private Random random = new Random();
    private JMenuBar menuBar;
    private JFrame frame;
    private BufferedImage spaceBackground;

    public static void main(String[] args)
    {
        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run(){
                new Breakout();
            }
        });
    }

    public Breakout()
    {
        graphicsOn = true;
        frame = new JFrame("Breakout");
        frame.setSize(806, 933);
        frame.setResizable(false);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.add(this);
        frame.setVisible(true);

        ball = new Ball();
        paddle = new Paddle();
        brick = new Brick[99];
        
        try{
            spaceBackground = ImageIO.read(new File("space.jpg"));
        }catch(IOException e){
            System.out.println("Could not open images, turning images off!");
            graphicsOn = false;
        }

        setFocusable(true);

        score = 0; lives = 4; level = 1;
        levelWon = false;
        addKeyListener(paddle);
        Brick.bricksAlive = 0;

        menuBar = new JMenuBar();
        JMenu difficultyMenu = new JMenu("Difficulty");
        JMenu graphicsMenu = new JMenu("Graphics");
        JMenu speedMenu = new JMenu("Paddle Speed");
        JMenu otherMenu = new JMenu("Other");
        menuBar.add(difficultyMenu);
        menuBar.add(graphicsMenu);
        menuBar.add(speedMenu);
        menuBar.add(otherMenu);

        final JCheckBoxMenuItem easyItem = new JCheckBoxMenuItem("Easy");
        final JCheckBoxMenuItem mediumItem = new JCheckBoxMenuItem("Medium");
        final JCheckBoxMenuItem hardItem = new JCheckBoxMenuItem("Hard");

        final JCheckBoxMenuItem graphicsOnItem = new JCheckBoxMenuItem("ON");
        final JCheckBoxMenuItem graphicsOffItem = new JCheckBoxMenuItem("OFF");

        final JCheckBoxMenuItem resetItem = new JCheckBoxMenuItem("Reset Game");

        final JCheckBoxMenuItem speedLow = new JCheckBoxMenuItem("Slow");
        final JCheckBoxMenuItem speedMedium = new JCheckBoxMenuItem("Medium");
        final JCheckBoxMenuItem speedHigh = new JCheckBoxMenuItem("High");

        graphicsOnItem.setSelected(true);
        mediumItem.setSelected(true);
        speedMedium.setSelected(true);

        speedLow.addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent e){
                paddle.setSpeed(15);
                speedLow.setSelected(true);
                speedMedium.setSelected(false);
                speedHigh.setSelected(false);
            }
        });
        speedMenu.add(speedLow);

        speedMedium.addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent e){
                paddle.setSpeed(20);
                speedLow.setSelected(false);
                speedMedium.setSelected(true);
                speedHigh.setSelected(false);
            }
        });
        speedMenu.add(speedMedium);
        
        speedHigh.addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent e){
                paddle.setSpeed(35);
                speedLow.setSelected(false);
                speedMedium.setSelected(false);
                speedHigh.setSelected(true);
            }
        });
        speedMenu.add(speedHigh);


        easyItem.addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent e){
                easyItem.setSelected(true);
                mediumItem.setSelected(false);
                hardItem.setSelected(false);
                ball.changeSpeedCounter(15);
                paddle.setSize(200,25);
            }
        });
        difficultyMenu.add(easyItem);

        mediumItem.addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent e){
                easyItem.setSelected(false);
                mediumItem.setSelected(true);
                hardItem.setSelected(false);
                ball.changeSpeedCounter(10);
                paddle.setSize(150, 25);
            }
        });
        difficultyMenu.add(mediumItem);

        hardItem.addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent e){
                easyItem.setSelected(false);
                mediumItem.setSelected(false);
                hardItem.setSelected(true);
                ball.changeSpeedCounter(5);
                paddle.setSize(100, 20);
            }
        });
        difficultyMenu.add(hardItem);

        graphicsOnItem.addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent e){
                graphicsOnItem.setSelected(true);
                graphicsOffItem.setSelected(false);
                ball.setGraphics(true);
                paddle.setGraphics(true);
                graphicsOn = true;
                for(int i = 0; i < brickNum; i++)
                    brick[i].setGraphics(true);
            }
        });
        graphicsMenu.add(graphicsOnItem);

        graphicsOffItem.addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent e){
                graphicsOnItem.setSelected(false);
                graphicsOffItem.setSelected(true);
                ball.setGraphics(false);
                paddle.setGraphics(false);
                graphicsOn = false;
                for(int i = 0; i < brickNum; i++)
                    brick[i].setGraphics(false);
            }
        });
        graphicsMenu.add(graphicsOffItem);

        resetItem.addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent e){
                resetGame();
            }
        });
        otherMenu.add(resetItem);

        



        
        addKeyListener(new KeyAdapter(){
            @Override
            public void keyPressed(KeyEvent e)
            {
                if(e.getKeyCode() == KeyEvent.VK_SPACE){
                    ball.roll(400, 450, true);
                }
                if(e.getKeyCode() == KeyEvent.VK_ENTER && Brick.bricksAlive == 0){
                    nextLevel();
                }
                if(e.getKeyCode() == KeyEvent.VK_ENTER && lives == 0){
                    resetGame();
                }
            }
        });


        brickNum = 0;
        for(int row = 0; row < 11; ++row){
            for(int col = 0; col < 9; ++col){
               brick[brickNum] = new Brick(col*81+60, row*25+50, 1+random.nextInt(3)); 
               ball.addBallListener(brick[brickNum]);
               brickNum++;
            }
        }

        ball.addBallListener(paddle);
        frame.setJMenuBar(menuBar);

        Timer timer = new Timer(50, this);
        timer.start();
    }

    public void resetGame()
    {
        Brick.bricksAlive = 0;
        score = 0; lives = 4; level = 1;
        for(int i = 0; i < brickNum; i++)
            brick[i].reset(1+random.nextInt(3));

    }

    public void nextLevel()
    {
        Brick.bricksAlive = 0;
        levelWon = false;
        Breakout.lives++;
        for(int i = 0; i < brickNum; ++i)
            brick[i].reset(1+random.nextInt(3));
        level++;
    
    }
    
    @Override
    public void paintComponent(Graphics g)
    {
        super.paintComponent(g);
        setBackground(Color.LIGHT_GRAY);
        if(graphicsOn){
            g.drawImage(spaceBackground, 0, 0, 800, 900, null);
        }
        paddle.paintSprite(g);
        ball.paintSprite(g);
        for(int i = 0; i < brick.length; ++i)
            brick[i].paintSprite(g);
        if(graphicsOn)
            g.setColor(Color.GREEN);
        else
            g.setColor(Color.BLACK);
        g.setFont(new Font("TimesRoman", Font.PLAIN, 12));
        g.drawString("Score: " + Breakout.score, 50, 880);
        g.drawString("Level: " + level, 200, 880);
        g.drawString("Lives: " + Breakout.lives, 400, 880);
        if(Brick.bricksAlive == 0){
            ball.stopRolling();
            g.setFont(new Font("TimesRoman", Font.PLAIN, 20));
            g.drawString("Congratulations, you've won this round! press enter for next level",
                    25, 550);
        }
        if(lives == 0){
            g.setFont(new Font("TimesRoman", Font.PLAIN, 20));
            g.drawString("Sorry, you have run out of lives, press enter to try again!",
                    25, 550);
        }
    }

    public void actionPerformed(ActionEvent e)
    {
        repaint();
    }

}

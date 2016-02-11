/* 
 * Author        : Nathan Caron
 * Title         : TicTac
 * Last Modified : 10/07/2015
 * Assignment #  : 1
 * Purpose       : Create a Graphical tic tac toe game with images, and
 *               :  the choice to face 3 different difficulties of AI.
 *
 */

import java.util.List; // This is explicitly needed to prevent amiguity
import java.awt.*;
import java.util.*;
import java.awt.event.*;
import java.awt.image.*;
import java.awt.image.*;
import javax.swing.*;
import java.security.SecureRandom;
import java.io.*;
import javax.imageio.*;



public class TicTac extends JPanel
{
    private boolean useImages = true; // Set to false for regular X's and O's
    private enum Symbol { X, O, EMPTY };// Enum for X and O for turns and board
    private enum GameStatus { X_WIN, O_WIN, DRAW, CONTINUE };
    private enum Difficulty { EASY, HARD, IMPOSSIBLE };
    private Difficulty difficulty;
    private Symbol currentPlayer, ai;
    private Symbol[][] board;
    private GameStatus gameStatus;
    private int ROWS = 3, COLS = 3, cellSize = 100;
    // winConverted is the numbers that represent wins when in binary form
    private int[] winConverted = {448, 56, 7, 292, 146, 73, 273, 84};
    private int aiX, aiY; // used in AI hard to process moves
    private SecureRandom randomNumbers = new SecureRandom();
    private boolean multiPlayers, temp;
    private BufferedImage imageX, imageO, dragon; // images for X, O, background
    private BufferedImage sword, ring, saber, skull, hydra, smiley,
            background, night, finalfantasy;
    private Color PURPLE = new Color(128,0,128);

    private JLabel statusBar; // Display game status
    private JFrame frame;     // The frame to put everything on
    private JMenuBar menuBar; // The menu system to control options

///////////////////////////////////////////////////////////////////////////////
    
    /******************* Main to run the game *******************/
    public static void main(String[] args)
    {
      // Use EDT, was running into exceptions before so I added this
      SwingUtilities.invokeLater(new Runnable() {
         @Override
         public void run() {
            new TicTac();
         }
      });
    }

///////////////////////////////////////////////////////////////////////////////

    /** 
     *  Constructor to set everything up
     */
    public TicTac()
    {
        // Set defaults before settings are changed via menus
        // (defaults are vs AI, play as X, with graphics on)
        multiPlayers = false;
        temp = false;
        currentPlayer = Symbol.X;
        ai = Symbol.O;
        difficulty = Difficulty.IMPOSSIBLE;

        frame = new JFrame("Tic Tac Toe");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);
        // Set preferred size so game fills window nicely
        this.setPreferredSize(new Dimension(cellSize * ROWS, cellSize * COLS));
        frame.add(this);

        // Load images
        try{
            sword = ImageIO.read(new File("swordsBlue.png"));
            saber = ImageIO.read(new File("saber2.png"));
            skull = ImageIO.read(new File("skull.png"));
            ring = ImageIO.read(new File("ring.png"));
            smiley = ImageIO.read(new File("smiley.png"));
            hydra = ImageIO.read(new File("hydra.png"));
            finalfantasy = ImageIO.read(new File("finalfantasy.jpg"));
            dragon = ImageIO.read(new File("dargon.jpg"));
            night = ImageIO.read(new File("night.jpg"));
        } catch (IOException e) 
        {
            System.out.println("Could not open image files, turning images off!");
            useImages = false;
        }

        imageX = saber;
        imageO = ring;
        background = dragon;

        // Create menu bars.  Each one item will need a listener
        menuBar = new JMenuBar();
        JMenu menu = new JMenu("Mode");
        JMenu menu2 = new JMenu("Side");
        JMenu menu3 = new JMenu("Graphics");
        JMenu menu4 = new JMenu("Other");
        JMenu menu5 = new JMenu("Difficulty");
        JMenu xImageMenu = new JMenu("Image for X");
        JMenu oImageMenu = new JMenu("Image for O");
        JMenu backgroundMenu = new JMenu("Set Background");
        menuBar.add(menu);
        menuBar.add(menu2);
        menuBar.add(menu5);
        menuBar.add(menu3);
        menuBar.add(menu4);

        // Create checkbox menu items for choices
        final JCheckBoxMenuItem item = new JCheckBoxMenuItem("2 Player");
        final JCheckBoxMenuItem item2 = new JCheckBoxMenuItem("VS Computer");
        final JCheckBoxMenuItem item3 = new JCheckBoxMenuItem("Play as X");
        final JCheckBoxMenuItem item4 = new JCheckBoxMenuItem("Play as O");
        final JCheckBoxMenuItem item5 = new JCheckBoxMenuItem("On");
        final JCheckBoxMenuItem item6 = new JCheckBoxMenuItem("Off");
        JMenuItem item7 = new JMenuItem("Restart");
        JMenuItem item8 = new JMenuItem("Exit");
        final JCheckBoxMenuItem item9 = new JCheckBoxMenuItem("Easy");
        final JCheckBoxMenuItem item10 = new JCheckBoxMenuItem("Hard");
        final JCheckBoxMenuItem item11 = new JCheckBoxMenuItem("Impossible");
        final JCheckBoxMenuItem itemSword = new JCheckBoxMenuItem("Sword");
        final JCheckBoxMenuItem itemSaber = new JCheckBoxMenuItem("Sabers");
        final JCheckBoxMenuItem itemSkull = new JCheckBoxMenuItem("Skull");
        final JCheckBoxMenuItem itemRing = new JCheckBoxMenuItem("One Ring");
        final JCheckBoxMenuItem itemSmiley = new JCheckBoxMenuItem("Red Smiley");
        final JCheckBoxMenuItem itemHydra = new JCheckBoxMenuItem("Hydra");
        final JCheckBoxMenuItem itemDragon = new JCheckBoxMenuItem("Dragon");
        final JCheckBoxMenuItem itemFinalFantasy = new JCheckBoxMenuItem("Final Fantasy 7");
        final JCheckBoxMenuItem itemNight = new JCheckBoxMenuItem("Nighttime");

        
        // Set the initial checkboxes to true (for play vs ai, as X, with graphics on)
        item2.setSelected(true);
        item3.setSelected(true);
        item5.setSelected(true);
        item11.setSelected(true);
        itemSaber.setSelected(true);
        itemRing.setSelected(true);
        itemDragon.setSelected(true);

        // Play against friend
        item.addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent e){
                item.setSelected(true);
                item2.setSelected(false);
                multiPlayers = true;
                repaint();
            }
        });
        menu.add(item);

        // Checkbox for Selecting to play against AI
        item2.addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent e){
                item2.setSelected(true);
                item.setSelected(false);
                if(currentPlayer == Symbol.X)
                    ai = Symbol.O;
                else
                    ai = Symbol.X;
                item3.setSelected(true);
                item4.setSelected(false);
                multiPlayers = false;
            }
        });
        menu.add(item2);

        // Play as X
        item3.addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent e){
                // use temp variable to move after assigning symbols
                if(item4.getState() && !multiPlayers)
                   temp = true;
                item3.setSelected(true);
                item4.setSelected(false);
                currentPlayer = Symbol.X;
                ai = Symbol.O;
                if(temp)
                    aiMove();
                repaint();
                temp = false;
            }
        });
        menu2.add(item3);

        // Play as O
        item4.addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent e){
                if(item3.getState() && !multiPlayers)
                   temp = true;
                item4.setSelected(true);
                item3.setSelected(false);
                currentPlayer = Symbol.O;
                ai = Symbol.X;
                if(temp)
                    aiMove();
                repaint();
                temp = false;
            }
        });
        menu2.add(item4);

        // Turn Graphics on
        item5.addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent e){
                item5.setSelected(true);
                item6.setSelected(false);
                useImages = true;
                repaint();
            }
        });
        menu3.add(item5);

        // Turn Graphics off
        item6.addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent e){
                item5.setSelected(false);
                item6.setSelected(true);
                useImages = false;
                repaint();
            }
        });
        menu3.add(item6);
        menu3.addSeparator();
        menu3.add(xImageMenu);
        menu3.add(oImageMenu);
        menu3.add(backgroundMenu);

        // Choose Saber for X
        itemSaber.addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent e){
                itemSword.setSelected(false);
                itemSaber.setSelected(true);
                itemSkull.setSelected(false);
                imageX = saber;
                repaint();
            }
        });
        xImageMenu.add(itemSaber);

        // Choose Sword for X
        itemSword.addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent e){
                itemSword.setSelected(true);
                itemSaber.setSelected(false);
                itemSkull.setSelected(false);
                imageX = sword;
                repaint();
            }
        });
        xImageMenu.add(itemSword);

        // Choose Skull for X
        itemSkull.addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent e){
                itemSword.setSelected(false);
                itemSaber.setSelected(false);
                itemSkull.setSelected(true);
                imageX = skull;
                repaint();
            }
        });
        xImageMenu.add(itemSkull);

        // Choose ring for O
        itemRing.addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent e){
                itemRing.setSelected(true);
                itemSmiley.setSelected(false);
                itemHydra.setSelected(false);
                imageO = ring;
                repaint();
            }
        });
        oImageMenu.add(itemRing);

        // Choose red smiley for O
        itemSmiley.addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent e){
                itemRing.setSelected(false);
                itemSmiley.setSelected(true);
                itemHydra.setSelected(false);
                imageO = smiley;
                repaint();
            }
        });
        oImageMenu.add(itemSmiley);

        // Choose hydra for O
        itemHydra.addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent e){
                itemRing.setSelected(false);
                itemSmiley.setSelected(false);
                itemHydra.setSelected(true);
                imageO = hydra;
                repaint();
            }
        });
        oImageMenu.add(itemHydra);

        // Set dragon as background
        itemDragon.addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent e){
                itemDragon.setSelected(true);
                itemFinalFantasy.setSelected(false);
                itemNight.setSelected(false);
                background = dragon;
                repaint();
            }
        });
        backgroundMenu.add(itemDragon);

        // Set final fantasy 7 as background
        itemFinalFantasy.addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent e){
                itemDragon.setSelected(false);
                itemFinalFantasy.setSelected(true);
                itemNight.setSelected(false);
                background = finalfantasy;
                repaint();
            }
        });
        backgroundMenu.add(itemFinalFantasy);

        // Set night as background
        itemNight.addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent e){
                itemDragon.setSelected(false);
                itemFinalFantasy.setSelected(false);
                itemNight.setSelected(true);
                background = night;
                repaint();
            }
        });
        backgroundMenu.add(itemNight);

        // Reset game
        item7.addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent e){
                initialize();
            }
        });
        menu4.add(item7);

        // Exit game
        item8.addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent e){
                System.exit(0);
            }
        });
        menu4.add(item8);

        // Difficulty easy
        item9.addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent e){
                difficulty = Difficulty.EASY;
                item9.setSelected(true);
                item10.setSelected(false);
                item11.setSelected(false);
            }
        });
        menu5.add(item9);

        // Difficulty hard
        item10.addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent e){
                difficulty = Difficulty.HARD;
                item10.setSelected(true);
                item9.setSelected(false);
                item11.setSelected(false);
            }
        });
        menu5.add(item10);

        // Difficulty impossible
        item11.addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent e){
                difficulty = Difficulty.IMPOSSIBLE;
                item11.setSelected(true);
                item9.setSelected(false);
                item10.setSelected(false);
            }
        });
        menu5.add(item11);


        // Add Whole menu bar to frame
        frame.setJMenuBar(menuBar);

        // Create statusBar (updates will take place in paintComponent)
        statusBar = new JLabel("  ");
        statusBar.setFont(new Font(Font.DIALOG_INPUT, Font.BOLD, 15));
        statusBar.setBorder(BorderFactory.createEmptyBorder(2,5,4,5));
        // Use container variable to set layout and pack everything nicely
        Container cp = frame.getContentPane();
        cp.setLayout(new BorderLayout());
        cp.add(this, BorderLayout.CENTER);
        cp.add(statusBar, BorderLayout.SOUTH);
        frame.pack();

        board = new Symbol[ROWS][COLS];
        initialize();

        // Add the mouse listener.  Use MouseAdapter rather than implement it
        this.addMouseListener(new MouseAdapter() {
            @Override
            public void mouseClicked(MouseEvent e)
            {
                int currentCol = e.getX() / cellSize;
                int currentRow = e.getY() / cellSize;

                if(gameStatus == GameStatus.CONTINUE)
                {
                    // If valid click, and spot is empty, make the move.  Then check
                    // to see if game is won. If not, and facing AI, ai moves. 
                    // Otherwise switch X and O
                    if(currentRow >= 0 && currentRow < ROWS && currentCol >= 0
                        && currentCol < COLS && board[currentRow][currentCol] == Symbol.EMPTY)
                    {
                        board[currentRow][currentCol] = currentPlayer;
                        checkState(currentPlayer);

                        if(multiPlayers)
                            currentPlayer = (currentPlayer == Symbol.X) ? Symbol.O : Symbol.X;

                        if(gameStatus == GameStatus.CONTINUE && !multiPlayers)
                            aiMove();
                    }
                } else {
                    // Game is over, so re-initialize everything
                    initialize();
                }
                repaint();
            }
        });
    }
///////////////////////////////////////////////////////////////////////////////

    /** Initialize game, set all spots to empty, and
     *  if it is ai's turn, have it move 
     */
    public void initialize()
    {
        for(int y = 0; y < ROWS; ++y)
            for(int x = 0; x < COLS; ++x)
                board[y][x] = Symbol.EMPTY;
        gameStatus = GameStatus.CONTINUE;

        if(currentPlayer == Symbol.O && !multiPlayers)
            aiMove();
        if(currentPlayer == Symbol.O && multiPlayers)
            currentPlayer = Symbol.X; // X goes first
        repaint();
    }

///////////////////////////////////////////////////////////////////////////////

    /** Have the ai move, I have this call another method so I can
     *  add separate difficulties if I have time
     */
    public void aiMove()
    {
        if(difficulty == Difficulty.IMPOSSIBLE){
            int[] move = move();
            board[move[0]][move[1]] = ai;
            aiX = move[1]; aiY = move[0];
        }
        if(difficulty == Difficulty.EASY)
            aiMoveHeur();
        if(difficulty == Difficulty.HARD)
            aiMoveHard();

        checkState(ai);
    }

///////////////////////////////////////////////////////////////////////////////

    /** 
     *  This is the harder version, It will take win if possible, if not
     *  it will look to block you from getting a win, and if not it will
     *  just pick any random move.
     */
    public void aiMoveHard()
    {
        // generate moves if no immediate win or block
        int moveX = randomNumbers.nextInt(3);
        int moveY = randomNumbers.nextInt(3);


        //check for chances to win
        for(int x = 0; x < 3; x++){
            if(board[x][0] == ai && board[x][1] == ai){
                if(board[x][2] == Symbol.EMPTY){
                    board[x][2] = ai;
                    aiX = 2; aiY = x;
                    return;
                }
            }
            if(board[x][1] == ai && board[x][2] == ai){
                if(board[x][0] == Symbol.EMPTY){
                    board[x][0] = ai;
                    aiX = 0; aiY = x;
                    return;
                }
            }
            if(board[x][0] == ai && board[x][2] == ai){
                if(board[x][1] == Symbol.EMPTY){
                    board[x][1] = ai;
                    aiX = 1; aiY = x;
                    return;
                }
            }
            if(board[0][x] == ai && board[1][x] == ai){
                if(board[2][x] == Symbol.EMPTY){
                    board[2][x] = ai;
                    aiX = x; aiY = 2;
                    return;
                }
            }
            if(board[0][x] == ai && board[2][x] == ai){
                if(board[1][x] == Symbol.EMPTY){
                    board[1][x] = ai;
                    aiX = x; aiY = 1;
                    return;
                }
            }
            if(board[1][x] == ai && board[2][x] == ai){
                if(board[0][x] == Symbol.EMPTY){
                    board[0][x] = ai;
                    aiX = x; aiY = 0;
                    return;
                }
            }
        } // end for loop

        // Check diagonals for chances to win
        if(board[1][1] == ai && board[0][0] == ai){
            if(board[2][2] == Symbol.EMPTY){
                board[2][2] = ai;
                aiX = aiY = 2;
                return;
            }
        }
        if(board[0][0] == ai && board[2][2] == ai){
            if(board[1][1] == Symbol.EMPTY){
                board[1][1] = ai;
                aiX = aiY = 1;
                return;
            }
        }
        if(board[1][1] == ai && board[2][2] == ai){
            if(board[0][0] == Symbol.EMPTY){
                board[0][0] = ai;
                aiX = aiY = 0;
                return;
            }
        }
        // Check columns and Rows for danger
        for(int x = 0; x < 3; x++){
            if(board[x][0] == currentPlayer && board[x][1] == currentPlayer){
                if(board[x][2] == Symbol.EMPTY){
                    board[x][2] = ai;
                    aiX = 2; aiY = x;
                    return;
                }
            }
            if(board[x][1] == currentPlayer && board[x][2] == currentPlayer){
                if(board[x][0] == Symbol.EMPTY){
                    board[x][0] = ai;
                    aiX = 0; aiY = x;
                    return;
                }
            }
            if(board[x][0] == currentPlayer && board[x][2] == currentPlayer){
                if(board[x][1] == Symbol.EMPTY){
                    board[x][1] = ai;
                    aiX = 1; aiY = x;
                    return;
                }
            }
            if(board[0][x] == currentPlayer && board[1][x] == currentPlayer){
                if(board[2][x] == Symbol.EMPTY){
                    board[2][x] = ai;
                    aiX = x; aiY = 2;
                    return;
                }
            }
            if(board[0][x] == currentPlayer && board[2][x] == currentPlayer){
                if(board[1][x] == Symbol.EMPTY){
                    board[1][x] = ai;
                    aiX = x; aiY = 1;
                    return;
                }
            }
            if(board[1][x] == currentPlayer && board[2][x] == currentPlayer){
                if(board[0][x] == Symbol.EMPTY){
                    board[0][x] = ai;
                    aiX = x; aiY = 0;
                    return;
                }
            }
        }// end for loop

        // Check diagonals for danger
        if(board[1][1] == currentPlayer && board[0][0] == currentPlayer){
            if(board[2][2] == Symbol.EMPTY){
                board[2][2] = ai;
                aiX = aiY = 2;
                return;
            }
        }
        if(board[0][0] == currentPlayer && board[2][2] == currentPlayer){
            if(board[1][1] == Symbol.EMPTY){
                board[1][1] = ai;
                aiX = aiY = 1;
                return;
            }
        }
        if(board[1][1] == currentPlayer && board[2][2] == currentPlayer){
            if(board[0][0] == Symbol.EMPTY){
                board[0][0] = ai;
                aiX = aiY = 0;
                return;
            }
        }
        if(board[0][2] == currentPlayer && board[1][1] == currentPlayer){
            if(board[2][0] == Symbol.EMPTY){
                board[2][0] = ai;
                aiX = 0; aiY = 2;
                return;
            }
        }
        if(board[1][1] == currentPlayer && board[2][0] == currentPlayer){
            if(board[0][2] == Symbol.EMPTY){
                board[0][2] = ai;
                aiX = 2; aiY = 0;
                return;
            }
        }
        if(board[0][2] == currentPlayer && board[2][0] == currentPlayer){
            if(board[1][1] == Symbol.EMPTY){
                board[1][1] = ai;
                aiX = aiY = 1;
                return;
            }
        }
        // No wins or losses this turn, moving on
        while(!noMoreMoves()){
            if(board[moveX][moveY] == Symbol.EMPTY){
                board[moveX][moveY] = ai;
                aiX = moveY; aiY = moveX;
                return;
            }
            moveX = randomNumbers.nextInt(3);
            moveY = randomNumbers.nextInt(3);
        }
    }

////////////////////////////////////////////////////
        
    /** 
     * Simple algorithm that doesn't work too well
     * I use this one for Easy mode
     */
    public void aiMoveHeur()
    {
        int score1 = 0;
        int score2 = 0;
        int bestCol = 0;
        int bestRow = 0;
        int bestScore = 0;


        for(int row = 0; row < 3; row++){
            for(int col = 0; col < 3; col++){
                if(board[row][col] != Symbol.EMPTY)
                    continue;
                for(int curRow = 0; curRow < 3; curRow++){
                    if(board[curRow][col] == ai)
                        score1 += 10;
                    if(board[curRow][col] == currentPlayer)
                        score1 += 8;
                }
                for(int curCol = 0; curCol < 3; curCol++){
                    if(board[row][curCol] == ai)
                        score2 += 10;
                    if(board[row][curCol] == currentPlayer)
                        score2 += 8;
                }
                if(score1 > bestScore){
                    bestScore = score1;
                    bestRow = row;
                    bestCol = col;
                }

                if(score2 > bestScore){
                    bestScore = score2;
                    bestRow = row;
                    bestCol = col;
                }
                score1 = 0;
                score2 = 0;
            } // end col
        }

        board[bestRow][bestCol] = ai;
        aiX = bestCol; aiY = bestRow;
    } // end method

///////////////////////////////////////////////////////////////////////////////

    /**
     *  Check state of game(Win/Loss/Draw)
     */
    public void checkState(Symbol curr)
    {
        if(checkForWin(curr)){
            if(curr == Symbol.X)
                gameStatus = GameStatus.X_WIN;
            else
                gameStatus = GameStatus.O_WIN;
        } else if(noMoreMoves()){
            gameStatus = GameStatus.DRAW;
        }
    }

///////////////////////////////////////////////////////////////////////////////

    /**
     *  Check to see if there are no moves left
     */
    public boolean noMoreMoves()
    {
        for(int y = 0; y < ROWS; ++y)
            for(int x = 0; x < COLS; ++x)
                if(board[y][x] == Symbol.EMPTY)
                    return false;
        return true;
    }

///////////////////////////////////////////////////////////////////////////////

    /**
     *  Converts the player called (turn) into a decimal number whose binary
     *  represents the board if it were expressed as a 1d array
     *  It then bitwise ANDS the board (positions) with the winning boards,
     *  which will then equal that board if it is a winning position
     */
    public boolean checkForWin(Symbol turn)
    {
        int positions = 0;
        // Use bit shifting to create binary pattern of the board
        // If board[row][col] = player being checked, will OR the
        // positions with the bit 256 shifted to the right row*3+col times
        // (ie if player has first 3 boxes, pattern will = 448)
        for(int row = 0; row < ROWS; ++row)
            for(int col = 0; col < COLS; ++col)
                if(board[row][col] == turn)
                    positions |= (256 >> (row * COLS + col));
        for(int x : winConverted)
            if((positions & x) == x) // Use bitwise AND comparison
                return true;
        // If it gets to this point, there is no win, so return false
        return false;
    }

///////////////////////////////////////////////////////////////////////////////

    /**
     *  PaintComponent to draw everything.
     */
    @Override
    public void paintComponent(Graphics g)
    {
        super.paintComponent(g);
        setBackground(Color.WHITE);
        // If using images, use cool dragon background
        if(useImages)
            g.drawImage(background, 0, 0, 310, 300, null);

        // Use light gray to not overpower the background image
        g.setColor(Color.LIGHT_GRAY);
        for(int y = 1; y < ROWS; ++y)
            g.fillRoundRect(0, cellSize * y - 4, (cellSize * COLS)-1,8,8,8);
        for(int x = 1; x < COLS; ++x)
            g.fillRoundRect(cellSize * x -4, 0, 8, (cellSize * ROWS)-1,8,8);

        // Use graphics2d for when not using the images
        Graphics2D g2d = (Graphics2D)g;
        g2d.setStroke(new BasicStroke(4, BasicStroke.CAP_ROUND, BasicStroke.JOIN_ROUND));
        for(int y = 0; y < ROWS; ++y){
            for(int x = 0; x < COLS; ++x){
                int x1 = x * cellSize + 16;
                int y1 = y * cellSize + 16;
                if(board[y][x] == Symbol.X){
                    // use image if set to true, otherwise use g2d
                    // for thicker, better looking X's and O's
                    if(useImages)
                        g.drawImage(imageX, x1, y1, 75, 75, null);
                    else{
                        g2d.setColor(PURPLE);
                        int x2 = (x + 1) * cellSize - 16;
                        int y2 = (y + 1) * cellSize - 16;
                        g2d.drawLine(x1, y1, x2, y2);
                        g2d.drawLine(x2, y1, x1, y2);
                    }
                } else if(board[y][x] == Symbol.O){
                    if(useImages)
                        g.drawImage(imageO, x1, y1, 75, 75, null);
                    else{
                        g2d.setColor(Color.BLUE);
                        g2d.drawOval(x1, y1, 70, 70);
                    }
                }
            }//end for
        }

        // Set status bar based on gamestate.  If CONTINUE, show whose turn it is
        if(gameStatus == GameStatus.CONTINUE){
            statusBar.setForeground(Color.BLACK);
            if(currentPlayer == Symbol.X)
                statusBar.setText("X's Turn");
            else
                statusBar.setText("O's Turn");
        } else if(gameStatus == GameStatus.DRAW){
            statusBar.setForeground(Color.RED);
            statusBar.setText("Draw! Click to play again!");
        } else if(gameStatus == GameStatus.X_WIN){
            statusBar.setForeground(Color.RED);
            statusBar.setText("X has won! Click to play again!");
        } else if(gameStatus == GameStatus.O_WIN){
            statusBar.setForeground(Color.RED);
            statusBar.setText("O has won! Click to play again!");
        }
    }

/////////////////////////////////////////////////////////////////////////////////


    /**
     *  Function to call minimax and return the best move as [row, col] 
     */
    public int[] move()
    {
        // depth, max-turn, alpha, beta
        int[] result = minimax(2, ai, Integer.MIN_VALUE, Integer.MAX_VALUE);
        return new int[] {result[1], result[2]}; // row, col
    }

///////////////////////////////////////////////////////////////////////////////

    /** 
     *  Famous minimax algorithm with alpha/beta pruning, this will
     *  make the AI unbeatable, however as it is tictactoe it is easy to tie
     *  This algorithm looks 2 moves ahead and scores moves based on assuming
     *  its opponent will make the smartest possible moves
     *  It is called minimax because one player is minimizing and wants the
     *  lowest possible score, and the other is maximizing and wants the highest
     */
    public int[] minimax(int depth, Symbol turn, int alpha, int beta)
    {
        List<int[]> moves = getMoves();
        int score;
        int bestRow = -1, bestCol = -1;

        if(moves.isEmpty() || depth == 0){
            score = getScore();
            return new int[] {score, bestRow, bestCol};
        }else{
            for(int[] move : moves){
                board[move[0]][move[1]] = turn;
                if(turn == ai){ // maximizing player
                    score = minimax(depth - 1, currentPlayer, alpha, beta)[0];
                    if(score > alpha){
                        alpha = score;
                        bestRow = move[0];
                        bestCol = move[1];
                    }
                }else{  //minimizing player
                    score = minimax(depth - 1, ai, alpha, beta)[0];
                    if(score < beta){
                        beta = score;
                        bestRow = move[0];
                        bestCol = move[1];
                    }
                }
                // Reset move (doing it this way and resetting makes it so
                // you don't have to keep creating boards like some minimax
                // algorithms do.)
                board[move[0]][move[1]] = Symbol.EMPTY;
                if(alpha >= beta)
                    break;
            }//end for
            return new int[]{ (turn == ai) ? alpha : beta, bestRow, bestCol};
        }
    }

///////////////////////////////////////////////////////////////////////////////

    /**
     *  Get a list of open moves, return empty list if
     *  game is over
     */
    public List<int[]> getMoves()
    {
        List<int[]> moves = new ArrayList<int[]>();

        if(checkForWin(ai) || checkForWin(currentPlayer))
            return moves;

        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(board[row][col] == Symbol.EMPTY)
                    moves.add(new int[] {row, col});
            }
        }
        return moves;
    }

///////////////////////////////////////////////////////////////////////////////

    /**
     *  Call evaluate with each possible move
     *  and add up all scores to get total score
     */
    public int getScore()
    {
        // I chose a 3d array so I could use a for loop with evaluate
        // lines has all winning board possiblilities (same as winConverted
        // except with row and column pairs, which we need to evaluate scores)
        int[][][] lines = {  {  {0,0},{0,1},{0,2}  },{  {1,0},{1,1},{1,2}  },
                             {  {2,0},{2,1},{2,2}  },{  {0,0},{1,0},{2,0}  },
                             {  {0,1},{1,1},{2,1}  },{  {0,2},{1,2},{2,2}  },
                             {  {0,0},{1,1},{2,2}  },{  {0,2},{1,1},{2,0}  }  };
        int score = 0;
        for(int i = 0; i < lines.length; ++i)
            score += evaluate(lines[i]);
        return score;
    }

///////////////////////////////////////////////////////////////////////////////

    /** 
     * Evaluate scores of potential moves 
     */
    public int evaluate(int[][] line)
    {
        int score = 0;
        int row = line[0][0], col = line[0][1];

        // AI is maximizing so if in ai favor, positive numbers,
        // if in player's favor, negative numbers.
        if(board[row][col] == ai)
            score = 1;
        else if(board[row][col] == currentPlayer)
            score = -1;

        row = line[1][0]; col = line[1][1];
        if(board[row][col] == ai){
            if(score == 1)
                score = 10;
            else if(score == -1)
                return 0;
            else
                score = 1;
        }else if(board[row][col] == currentPlayer){
            if(score == -1)
                score = -10;
            else if(score == 1)
                return 0;
            else
                score = -1;
        }

        row = line[2][0]; col = line[2][1];
        if(board[row][col] == ai){
            if(score > 0)
                score *= 10;
            else if(score < 0)
                return 0;
            else
                score = 1;
        }else if(board[row][col] == currentPlayer){
            if(score < 0)
                score *= 10;
            else if(score > 1)
                return 0;
            else
                score = -1;
        }
        return score;
    }
}

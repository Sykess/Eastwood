/**
 * FileName: TurtleGraphics.java
 * @author (Sandeep Negi)
 * MCA 2nd Year
 * Java Programming Lab-406
 */
 
class TurtleGraphics {
 
boolean floor[][];
boolean penStatus;
int moveType;
int status;
int x;
int y;
 
private void init() {
floor = new boolean[20][20];
for (int i = 0; i < 20; i++)
for (int j = 0; j < 20; j++)
 
floor[i][j] = false;
 
penStatus = false;
moveType = 0;
status = -1;
x = 0;
y = 0;
 
}
 
public TurtleGraphics() {
 
init();
 
}
 
private void drawPixel(int to) {
 
int cX = x;
 
int cY = y;
 
if (moveType == 0 && penStatus) {
 
while (cY + to <= 20 && y < cY + to)
 
floor[x][y++] = true;
 
y--;
 
} else if (moveType == 1 && penStatus) {
 
while (cX + to <= 20 && x < cX + to)
 
floor[x++][y] = true;
 
x--;
 
} else if (moveType == 2 && penStatus) {
 
while (cY + 1 - to >= 0 && cY - y < to)
 
floor[x][y--] = true;
 
y++;
 
} else if (moveType == 3 && penStatus) {
 
while (cX + 1 - to >= 0 && cX - x < to)
 
floor[x--][y] = true;
 
x++;
 
}
 
}
 
private void drawTurtle() {
 
for (int i = 0; i < 20; i++) {
 
for (int j = 0; j < 20; j++)
 
System.out.print(floor[i][j] ? "* " : "  ");
 
System.out.println();
 
}
 
}
 
public void makeTurtle(int... input) {
 
if (input.length > 0 && input.length <= 2) {
 
if (input.length == 1) {
 
if (input[0] == 1 || input[0] == 2)
 
penStatus = input[0] % 2 == 0;
 
else if (input[0] == 3 || input[0] == 4) {
 
if (status == 0) {
 
moveType = (input[0] == 3) ? ((moveType == 0) ? 1
 
: (moveType == 1) ? 2 : (moveType == 2) ? 3 : 0)
 
: ((moveType == 0) ? 3 : (moveType == 1) ? 0
 
: (moveType == 2) ? 1 : 2);
 
} else
 
System.out.println("Invalid State");
 
} else if (input[0] == 6)
 
drawTurtle();
 
else if (input[0] == 9)
 
init();
 
else
 
System.out.println("Exception Occurred");
 
} else {
 
if (status == -1) {
 
if (y + input[1] > 20) {
 
System.out.println("Can't Plot");
 
} else {
 
status = 0;
 
drawPixel(input[1]);
 
}
 
} else {
 
if (moveType == 0) {
 
if (y + input[1] > 20) {
 
System.out.println("Can't Plot");
 
} else
 
drawPixel(input[1]);
 
} else if (moveType == 1) {
 
if (x + input[1] > 20) {
 
System.out.println("Can't Plot");
 
} else
 
drawPixel(input[1]);
 
} else if (moveType == 2) {
 
if (y + 1 - input[1] < 0) {
 
System.out.println("Can't Plot");
 
} else
 
drawPixel(input[1]);
 
} else if (moveType == 3) {
 
if (x + 1 - input[1] < 0) {
 
System.out.println("Can't Plot");
 
} else
 
drawPixel(input[1]);
 
} else {
 
System.out.println("Invalid Move");
 
}
 
}
 
}
 
} else
 
System.out.println("Exception Occurred");
 
}
 
public static void main(String[] args) {
 
TurtleGraphics turtleGraphics = new TurtleGraphics();
 
String inputData = "2 5,12 3 5,12 3 5,12 3 5,12 1 6 9";
 
String tempStr[] = inputData.split(" ");
 
for (int i = 0; i < tempStr.length; i++) {
 
String tempInput[] = tempStr[i].split(",");
 
int input[] = new int[tempInput.length];
 
for (int j = 0; j < tempInput.length; j++) {
 
input[j] = Integer.parseInt(tempInput[j]);
 
}
 
turtleGraphics.makeTurtle(input);
 
}
}
}
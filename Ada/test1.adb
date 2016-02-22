
with Ada.Text_IO; use Ada.Text_IO;

procedure test1 is
    -- Variable declarations
    A, B    : Integer := 0;
    C       : Integer := 100;
    D       : Integer;
    Variable: Integer := 5;
begin
    -- Maths:
    A := A + 1;
    D := A + B + C;
    Ada.Text_IO.Put_Line(Integer'Image(A)); -- need to use Ada.Text_IO if no use clause above
    Put_Line(Integer'Image(D));

    -- If statements:
    if Variable > 0 then
        Put_Line (" > 0 ");
    elsif Variable < 0 then
        Put_Line (" < 0 ");
    else
        Put_Line (" = 0 ");
    end if;
    -- words not, and, or replace symbols !, &, | for boolean operations
    -- equality is = and inequality is /=

    -- Switch statements
    case Variable is
        when 0 =>
            Put_Line("Zero"); -- note no breaks needed
        When 1 .. 9 =>
            Put_Line("Positive Digit");
        when 10 | 12 | 14 | 16 | 18 =>
            Put_Line("Even number between 10 and 18");
        when others => -- this is ada's default case
            Put_Line ("Something else");
    end case;

    -- Loops:
    while Variable < 10_000 loop
        Variable := Variable * 2;
    end loop;

    for Variable in 0 .. 9 loop
        --Put_Line (Integer'Image (Variable));
        null; -- must put null with empty body (commented output to cleanup)
    end loop;

    -- loop in reverse
    for Variable in reverse 0 .. 9 loop
        --Put_Line (Integer'Image (Variable));
        null;
    end loop;

    -- If Int_List was array of Integer values, could iterate like such:
    -- for I of Int_List loop
    --     Put_Line (Integer'Image(I));
    -- end loop;

    -- Type conversion must be explicit:
    declare
        Alpha : Integer := 1;
        Beta  : Integer := 10;
        Result: Float;
    begin
        Result := Float (Alpha) / Float (Beta);
        Put_Line (Float'Image (Result));
    end;

    -- Created types:
    declare
        type Distance is new Float;
        type Area is new Float;
        D1 : Distance := 2.0; -- Must have .0 for float
        D2 : Distance := 3.0;
        A  : Area;
    begin
        D1 := D1 + D2;  -- Valid
        --D1 := D1 + A;   -- Not compatible
        --A  := D1 * D2;  -- Not compatible
        A  := Area (D1 * D2); -- Valid
    end;


    -- Enumeration stuff:
    declare
        type Day is 
            (Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday);
        -- To be able to compare enums with ints, must use clause like such:
        for Day use
            (Monday => 10, Tuesday => 11, Wednesday => 12, Thursday => 13,
             Friday => 14, Saturday => 15, Sunday => 16);
        type Buisness_day is new Day range Monday .. Friday;
        type Weekend_day is new Day range Saturday .. Sunday;
        -- Since these 2 are new types, implicit conversions are illegal.
        -- Instead can create subtypes instead of making new ones:
        subtype Business_day1 is Day range Monday .. Friday;
        subtype Weekend_day1 is Day range Saturday .. Sunday;
        subtype Dice_Throws is Integer range 1 .. 6;
        -- Can also use predicates as of Ada 2012
        subtype Dice_Throw is Integer
            with Dynamic_Predicate => Dice_Throw in 1 .. 6;
        -- Can also be used to represent types with arbitrary constraints:
        type Not_Null is new Integer
            with Dynamic_Predicate => Not_Null /= 0;
        type Even is new Integer
            with Dynamic_Predicate => Even mod 2 = 0;
    -- empty begin/end since I don't do anything with this stuff
    begin
        null;
    end;

    -- Creating types with ranges
    declare
        type Grade is range 0 .. 100;
        G1, G2  : Grade;
        N       : Integer;
    begin
        N := 20;
        G1 := 30;        -- legal
        --G1 := N;         -- illegal
        G1 := Grade (N); -- legal, run time range check
        G2 := G1 + 10;   -- legal, run time range check
        G1 := (G1+G2)/2; -- legal, run time range check
    end;

    -- Transfer ints to strings and strings to int
    declare
        A : Integer := 99;
    begin
        Put_Line(Integer'Image (A));
        A := Integer'Value("99");
    end;

    -- To add 1 to a character's ascii value:
    declare
        C : Character := 'a';
    begin
        C := Character'Val (Character'Pos (C) + 1);
        -- Or can use the Succ attribute:
        C := Character'Succ (C);
        -- There is also the Pred attribute for previous char
    end;

    -- Can display First and Last attributes of things such as Ints:
    Put_Line(Integer'Image(Integer'First)); -- prints -2^31
    Put_Line (Integer'Image(Integer'Last)); -- prints 2^31 - 1




end test1;

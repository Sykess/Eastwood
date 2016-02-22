
with Ada.Text_IO;
use Ada.Text_IO;

procedure test2 is
    -- <> is pronounced "box" and specifies "no constraints"
    type Array_type is array (Integer range <>) of Character;
    -- Constraints declared 1-26, inclusive
    Arr : Array_type (1 .. 26);
    C : Character := 'a';
    -- Arrays have attribute called 'Range.  Arr'Range can be expressed as
    -- Arr'First .. Arr'Last, will resolve to 1 .. 26.  Range attribute supplies
    -- the bounds for the for loop.
begin
    for I in Arr'Range loop
        Arr (I) := C;
        C := Character'Succ (C);
        --Put_Line(Character'Image(c));
    end loop;

    -- Note: C++ or Java String class is equivalent to Ada's 
    -- Ada.Strings.Unbounded_String.
    -- Ada strings are not delimited with '\0' because array's bounds determine start/stop
    -- Using strings: 
    declare
        -- My_String : String (1 .. 26);
        -- Ada does not have escape sequences (\n) so the ASCII value must be added
        My_String : String := "This is a line with an end of line" & ASCII.LF;
        A1 : Array_type (1 .. 2);
        A2 : Array_type (1 .. 2);

    begin
        A1 (1) = 0;
        A1 (2) = 1;
        A2 := A1;
    end;




end test2;







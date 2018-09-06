
public class Variables
{
  public static void main(String[] args)
  {
    byte a;
	short b;
	int c;
	long d;

	d = c = b = a = 14;

	float y;
	double z;

	y = a / 3.0f;
	z = y*5;

	d = (long)z;
	System.out.println("d = " + d);
	System.out.println("z = " + z);

	char i;
	i = 'i';

	boolean j;
	j = y < z;
	System.out.println("y < z " + i + "s " + j);
  }
}

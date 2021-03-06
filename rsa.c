
#include <stdio.h>
#include <gmp.h>

int main()
{
	const char* str_modulo = "C8C69CEB031DC7856DAEAD47B7B9E3AB0B00FBDE78F65DE8D4AE2B7FA462010C60B4B1EE5BB901A1BC22B068A1807032AFBCCE28C259E191F9A7D547CE80DFB0A147ED5D1B5EFC46D8DA75BC15E79242D266D1ACEAEFC3774766C253B50B17B7200FE97A4737E9141B6E87E5D35DE94957AE395FED3001063F76855DB9F0512B884916BB4B35DF62BEB151F01711CAE0EDB8D4059DB4FAC131A4A761B68C526AF76DE3F61A7DA54CEC1B59E50F2547B42390C34B0320755EB8BD6D2A6F35FFA279311B6328AAE7740DC2D30EEC92F62991738653F26EC98F502C8651733A77B16BB3A6EDE1781F3FFDCB0E3EC8BBAAA2D14A026741CD26E849A212ACF8336E81";
	const char* str_e = "010001";
	const char* str_d = "B38EC4B97D20FDD63B8073A1E7130D246403EE3D49AAF3D38D9972778618CBDD390380F9ADF828186FFC0A0E991917BE8CE26AF192D6F5602A8949BA1D59AE33F61930940B2D88AB07B76081E489248A3447160FF250995C2C741F28E389D71CC444D6C6AFB8B5EF70950A5EA508A0E121D443A5A1A743D345A086A78AE9FC7C3CBBAB4FBEB43CBA17151CCA3581A1764A31C5BA7E09E738970E15F2D20A69296FDA6F3995805B95F792698CBB9BDF03138EDCD88134F3F0F4AA2837D6C0F76910A023F570260B8A93116A670C1B0A138EA3E4327256623EBD547669AEE8F4061B676B3A491BA7E1E6E7DF25FAFB89BDE5516DC42FEBF707B123A08BEC8E11BD";
	
	mpz_t mpz_message;
	mpz_t mpz_modulo;
	mpz_t mpz_e;
	mpz_t mpz_d;
	mpz_t mpz_encrypted;
	mpz_t mpz_decrypted;
	
	mpz_init(mpz_encrypted);
	mpz_init(mpz_message);
	mpz_init(mpz_modulo);
	mpz_init(mpz_e);
	mpz_init(mpz_d);
	mpz_init(mpz_decrypted);
	
	mpz_set_ui(mpz_message, 2020);
	mpz_set_str(mpz_modulo, str_modulo, 16);
	mpz_set_str(mpz_e, str_e, 16);
	mpz_set_str(mpz_d, str_d, 16);
	
	gmp_printf("modulo is: %Zx\n", mpz_modulo); 
	gmp_printf("exponent is is: %Zx\n" , mpz_e);
	gmp_printf("private exponent is: %Zx\n", mpz_d);
	
	mpz_powm(mpz_encrypted, mpz_message, mpz_e, mpz_modulo);
	
	gmp_printf("Encrypted is: %Zx\n", mpz_encrypted);
	mpz_powm(mpz_decrypted, mpz_encrypted, mpz_d, mpz_modulo);
	
	gmp_printf("Decrypted is: %Zd\n", mpz_decrypted);
	

	
	return 0;
}

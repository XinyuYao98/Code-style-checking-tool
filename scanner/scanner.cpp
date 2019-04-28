
#include<iostream>
#include<lib>
using RE = VBF.Compilers.Scanners.RegularExpression;

int main(){
	
	Lexicon lexicon = new Lexicon();
	LexerState lexer = lexicon.DefaultLexer;

	Token IF = lexer.DefineToken(RE.Literal("if"));
	Token ELSE = lexer.DefineToken(RE.Literal("else"));
	Token ID = lexer.DefineToken(RE.Range('a', 'z').Concat(
		(RE.Range('a', 'z') | RE.Range('0', '9')).Many()));
	Token NUM = lexer.DefineToken(RE.Range('0', '9').Many1());
	Token WHITESPACE = lexer.DefineToken(RE.Symbol(' ').Many());

	ScannerInfo info = lexicon.CreateScannerInfo();

	
	Scanner scanner = new Scanner(info);

	string source = "dec5f 1234 if";
	StringReader sr = new StringReader(source);

	scanner.SetSource(new SourceReader(sr));
	scanner.SetSkipTokens(WHITESPACE.Index);

	Lexeme l1 = scanner.Read();
	Console.WriteLine(l1.TokenIndex);
	Console.WriteLine(l1.Value);
	Lexeme l2 = scanner.Read();
	Console.WriteLine(l2.TokenIndex);
	Console.WriteLine(l2.Value);

	Lexeme l3 = scanner.Read();
	Console.WriteLine(l3.TokenIndex);
	Console.WriteLine(l3.Value);

	Lexeme l4 = scanner.Read();
	Console.WriteLine(l4.TokenIndex);
	Console.WriteLine(l4.Value);
}

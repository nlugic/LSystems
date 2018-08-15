
#include "LSystemGenerator.h"
#include "LSystem.h"

// funkcija koja parsira string simbola i dodaje ih proizvodu

namespace LSystemGeneratorAPI
{

	void LSystemGenerator::test()
	{
		lsys::LSystem ls1;

		ls1.addSymbolToAxiom(new lsys::LSystemSymbol('A'));
		
		lsys::LSystemProdRule *lr1 = new lsys::LSystemProdRule(new lsys::LSystemSymbol('A'));
		lr1->addSymbolToProduct(new lsys::LSystemSymbol('A'));
		lr1->addSymbolToProduct(new lsys::LSystemSymbol('B'));

		lsys::LSystemProdRule *lr2 = new lsys::LSystemProdRule(new lsys::LSystemSymbol('B'));
		lr2->addSymbolToProduct(new lsys::LSystemSymbol('A'));

		ls1.addRule(lr1);
		ls1.addRule(lr2);
		
		ls1.derive(8);
		
		lsys::LSystem ls2 = ls1;
		
		std::vector<lsys::LSystemSymbol *>& level1 = ls2[8];

		std::cout << ls2 << std::endl;

		for (lsys::LSystemSymbol *sym : level1)
			std::cout << *sym;
		std::cout << std::endl << std::endl;

		lsys::LSystem ls3;

		ls3.addSymbolToAxiom(new lsys::LSystemSymbol('0'));

		lsys::LSystemProdRule *lr3 = new lsys::LSystemProdRule(new lsys::LSystemSymbol('1'));
		lr3->addSymbolToProduct(new lsys::LSystemSymbol('1'));
		lr3->addSymbolToProduct(new lsys::LSystemSymbol('1'));

		lsys::LSystemProdRule *lr4 = new lsys::LSystemProdRule(new lsys::LSystemSymbol('0'));
		lr4->addSymbolToProduct(new lsys::LSystemSymbol('1'));
		lr4->addSymbolToProduct(new lsys::LSystemSymbol('['));
		lr4->addSymbolToProduct(new lsys::LSystemSymbol('0'));
		lr4->addSymbolToProduct(new lsys::LSystemSymbol(']'));
		lr4->addSymbolToProduct(new lsys::LSystemSymbol('0'));

		ls3.addRule(lr3);
		ls3.addRule(lr4);
		
		ls3.derive(3);
		
		std::vector<lsys::LSystemSymbol *> level2 = ls3[3];
		
		std::cout << ls3 << std::endl;

		for (lsys::LSystemSymbol *sym : level2)
			std::cout << *sym;
		std::cout << std::endl << std::endl;
		
		ls2 = ls3;
		ls3 = ls1;

		std::cout << ls2 << std::endl;

		std::vector<lsys::LSystemSymbol *> level3 = ls3[8];

		for (lsys::LSystemSymbol *sym : level3)
			std::cout << *sym;
		std::cout << std::endl << std::endl;

		std::vector<lsys::LSystemSymbol *> level4 = ls2[3];

		std::cout << ls3 << std::endl;

		for (lsys::LSystemSymbol *sym : level4)
			std::cout << *sym;
		std::cout << std::endl << std::endl;
	}

}

#include "Ecoco.h"
#include <vector>
#include "Ice.h"
#include "Penguin.h"
namespace EcocoDeFight{
	class Penguins{
	public:
		const static int PenguinCount = 2;
		Penguins(const Ecoco& ecoco);
		void Attack(bool toRight);
		void Update();
		int HoldingIceCount()const;
		bool IsHoldingIce()const;
		bool HoldIce(Ice* controller)const;
	private:
		const Ecoco& ecoco;
		std::vector < Penguin > penguins;
	};
}
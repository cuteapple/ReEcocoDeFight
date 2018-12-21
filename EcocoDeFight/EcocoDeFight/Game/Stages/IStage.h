#ifndef ECOCO_DE_FIGHT_ISTAGE_H
#define ECOCO_DE_FIGHT_ISTAGE_H
namespace EcocoDeFight{
	class IStage
	{
	public:
		virtual void Update() = 0;
		virtual void Paint() = 0;
		virtual ~IStage(){}
	};
};

#endif
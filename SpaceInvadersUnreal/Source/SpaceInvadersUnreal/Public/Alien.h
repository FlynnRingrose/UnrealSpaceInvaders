// Flynn's Rad Copyright

#pragma once

#include "GameFramework/Pawn.h"
#include "Alien.generated.h"

UCLASS()
class SPACEINVADERSUNREAL_API AAlien : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AAlien();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
    
    UFUNCTION(BlueprintImplementableEvent, Category = "Setup")
    void InitializeBugAlien();

    void MoveAlien();
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Static Mesh Assets")
    UInstancedStaticMeshComponent* StaticBugComponent;
    
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category= "Static Mesh Assets")
    UStaticMesh* StaticBugOpen;
    
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category= "Static Mesh Assets")
    UStaticMesh* StaticBugClosed;
    
    float MoveSpeed = 1.f;
    
    float TimeOfLastMove;
    
    float MoveDelay = 1.f;
    
    bool bIsAlienOpen;
};

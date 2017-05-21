// Flynn's Rad Copyright

#pragma once

#include "GameFramework/Pawn.h"
#include "Ship.generated.h"

UCLASS()
class SPACEINVADERSUNREAL_API AShip : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AShip();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
    
    //Moves the player ship.
    UFUNCTION(BlueprintCallable, Category="Movement")
    void MoveRight(float Scale);
    
    void MoveShip();
    
    float MoveSpeed = 1.f;
    
    float TimeOfLastMove;
    
    float MoveDelay = 0.025f;
};

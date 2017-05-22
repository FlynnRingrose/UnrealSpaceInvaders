// Flynn's Rad Copyright

#pragma once

#include "GameFramework/Pawn.h"
#include "PlayerProjectile.h"
#include "Ship.generated.h"

UCLASS()
class SPACEINVADERSUNREAL_API AShip : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AShip();
    
    UFUNCTION(BlueprintCallable, Category = "Firing")
    void ActivateMissile();

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
    
    double LastFireTime = 0.f;
    
    int32 LaunchSpeed = 1000;
    
    UPROPERTY(EditAnywhere, Category = "Setup")
    UStaticMeshComponent* PlayerShip = nullptr;
    
    UPROPERTY(EditDefaultsOnly, Category = "Setup")
    TSubclassOf<APlayerProjectile> PlayerProjectileBlueprint; //Unlike UClass*, this will only make the projectile available in the editor.
    
};

// Flynn's Rad Copyright

#pragma once

#include "GameFramework/Pawn.h"
#include "Alien.generated.h"

UENUM()
enum class EAlienMovementState : uint8
{
    MovingRight,
    MovingLeft,
    MovingDown
};

UCLASS()
class SPACEINVADERSUNREAL_API AAlien : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AAlien();
    
    EAlienMovementState GetAlienMovementState();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

    
    UPROPERTY(BlueprintReadOnly, Category = "State")
    EAlienMovementState AlienMovementState = EAlienMovementState::MovingRight;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
    
    UFUNCTION(BlueprintImplementableEvent, Category = "Setup")
    void InitializeBugAlien();

    UFUNCTION()
    void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);
    
    void MoveAlien();
    
    void AliensDance();
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Static Mesh Assets")
    UInstancedStaticMeshComponent* StaticBugComponent;
    
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category= "Static Mesh Assets")
    UStaticMesh* StaticBugOpen;
    
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category= "Static Mesh Assets")
    UStaticMesh* StaticBugClosed;
    
    float MoveSpeed = 1.f;
    
    float TimeOfLastMove;
    
    float MoveDelay = 1.f;
    
    float TimeOfLastDance;
    
    float DanceDelay = 1.f;
    
    bool bIsAlienOpen;
    
};

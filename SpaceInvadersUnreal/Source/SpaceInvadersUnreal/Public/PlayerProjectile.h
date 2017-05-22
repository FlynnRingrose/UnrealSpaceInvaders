// Flynn's Rad Copyright

#pragma once

#include "GameFramework/Actor.h"

#include "PlayerProjectile.generated.h"

class AShip;

UCLASS()
class SPACEINVADERSUNREAL_API APlayerProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APlayerProjectile();
    
    virtual void Tick(float DeltaTime) override;
    
    UFUNCTION(BlueprintCallable, Category = "Firing")
    void LaunchMissile(int32 LaunchSpeed);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
    UFUNCTION()
    void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);
    
    UPROPERTY(VisibleAnywhere, Category = "Components")
    UStaticMeshComponent* Missile = nullptr;
    
    UPROPERTY(EditAnywhere, Category = "Components")
    UProjectileMovementComponent* MissileMovement = nullptr;
};

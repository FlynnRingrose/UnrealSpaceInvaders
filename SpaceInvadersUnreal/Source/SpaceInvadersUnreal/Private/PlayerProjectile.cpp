// Flynn's Rad Copyright

#include "SpaceInvadersUnreal.h"
#include "PlayerProjectile.h"


// Sets default values
APlayerProjectile::APlayerProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    
    Missile = CreateDefaultSubobject<UStaticMeshComponent>(FName("MissileMesh"));
    RootComponent = Missile;
    
    MissileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(FName("Missile Movement"));
    MissileMovement->bAutoActivate= false;
}

// Called when the game starts or when spawned
void APlayerProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APlayerProjectile::LaunchMissile(int32 LaunchSpeed)
{
    MissileMovement->  SetVelocityInLocalSpace(FVector(0,0,1) * LaunchSpeed);
    MissileMovement->Activate();
}

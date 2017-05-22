// Flynn's Rad Copyright

#include "SpaceInvadersUnreal.h"
#include "PlayerProjectile.h"


// Sets default values
APlayerProjectile::APlayerProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    
    Missile = CreateDefaultSubobject<UStaticMeshComponent>(FName("MissileMesh"));
    SetRootComponent(Missile);
    Missile->SetNotifyRigidBodyCollision(true);
    Missile->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
    
    MissileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(FName("Missile Movement"));
    MissileMovement->UpdatedComponent = Missile;
    MissileMovement->bAutoActivate= false;
}

// Called when the game starts or when spawned
void APlayerProjectile::BeginPlay()
{
	Super::BeginPlay();
	Missile->OnComponentHit.AddDynamic(this, &APlayerProjectile::OnHit);
}

// Called every frame
void APlayerProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APlayerProjectile::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit)
{
    this->Destroy();
    UE_LOG(LogTemp, Warning, TEXT("%s"), *OtherComponent->GetName())
    //TODO Remove intance hit without blueprints.
    //TODO Only allow one missile on screen at one time.
}

void APlayerProjectile::LaunchMissile(int32 LaunchSpeed)
{
    MissileMovement->SetVelocityInLocalSpace(FVector(0,0,1) * LaunchSpeed);
    MissileMovement->Activate();
}

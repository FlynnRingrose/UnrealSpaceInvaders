// Flynn's Rad Copyright

#include "SpaceInvadersUnreal.h"
#include "Ship.h"


// Sets default values
AShip::AShip()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    
    USphereComponent* SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("RootComponent"));
    RootComponent = SphereComponent;
    
    PlayerShip = CreateDefaultSubobject<UStaticMeshComponent>(FName("PlayerShipMesh"));
    PlayerShip->SetupAttachment(RootComponent);
    
}

// Called when the game starts or when spawned
void AShip::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AShip::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
    

}

// Called to bind functionality to input
void AShip::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AShip::MoveRight(float Scale)
{
    //UE_LOG(LogTemp, Warning, TEXT("Move right value is %f"), Scale)
    FVector ShipDirection = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorForwardVector();
    
    if(GetWorld()->GetTimeSeconds() >= TimeOfLastMove + MoveDelay)
    {
        AddMovementInput(ShipDirection, Scale, true);
        TimeOfLastMove = GetWorld()->GetTimeSeconds();
    }
}

void AShip::ActivateMissile()
{
    APlayerProjectile* NewMissile = GetWorld()->SpawnActor<APlayerProjectile>(
        PlayerProjectileBlueprint,
        PlayerShip->GetSocketLocation(FName("MissileSocket")),
        PlayerShip->GetSocketRotation(FName("MissileSocket"))
        );
    
    NewMissile->LaunchMissile(LaunchSpeed);
    LastFireTime = FPlatformTime::Seconds();
}

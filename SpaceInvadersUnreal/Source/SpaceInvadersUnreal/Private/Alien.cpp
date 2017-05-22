// Flynn's Rad Copyright

#include "SpaceInvadersUnreal.h"
#include "Alien.h"


// Sets default values
AAlien::AAlien()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;
    
    InitializeBugAlien();
    
    USphereComponent* SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("RootComponent"));
    RootComponent = SphereComponent;
    
    //StaticBugComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticBugComponent"));
    //StaticBugComponent->SetupAttachment(RootComponent);
    
    StaticBugComponent = CreateDefaultSubobject<UInstancedStaticMeshComponent>(TEXT("InstancedBug"));
    StaticBugComponent->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AAlien::BeginPlay()
{
	Super::BeginPlay();
    bIsAlienOpen = false;
}

// Called every frame
void AAlien::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
    MoveAlien();
}

void AAlien::MoveAlien()
{
    if(GetWorld()->GetTimeSeconds() >= TimeOfLastMove + MoveDelay)
    {
        FVector AlienLocation = GetActorLocation();
        AlienLocation.X += 20.0f;
        SetActorLocation(AlienLocation, false);
        
        if(bIsAlienOpen == true)
        {
            StaticBugComponent->SetStaticMesh(StaticBugClosed);
            bIsAlienOpen = false;
        }
        
        else if(bIsAlienOpen == false)
        {
            StaticBugComponent->SetStaticMesh(StaticBugOpen);
            bIsAlienOpen = true;
        }
        
        TimeOfLastMove = GetWorld()->GetTimeSeconds();
    }
}

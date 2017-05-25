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
    
    StaticBugComponent = CreateDefaultSubobject<UInstancedStaticMeshComponent>(TEXT("InstancedBug"));
    StaticBugComponent->SetupAttachment(RootComponent);
    
    StaticBugComponent->SetNotifyRigidBodyCollision(true);
    StaticBugComponent->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
}

// Called when the game starts or when spawned
void AAlien::BeginPlay()
{
	Super::BeginPlay();
    bIsAlienOpen = false;
    StaticBugComponent->OnComponentHit.AddDynamic(this, &AAlien::OnHit);
    //StaticBugComponent->OnComponentBeginOverlap.AddDynamic(this, &AAlien::OnActorBeginOverlap);
}

// Called every frame
void AAlien::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
    MoveAlien();
    AliensDance();
}

void AAlien::MoveAlien()
{
    if(GetWorld()->GetTimeSeconds() >= TimeOfLastMove + MoveDelay && bIsMovingRight == false)
    {
        AlienLocation = GetActorLocation();
        AlienLocation.X += 20.0f;
        SetActorLocation(AlienLocation, false);
        
        TimeOfLastMove = GetWorld()->GetTimeSeconds();
    }
    else if(GetWorld()->GetTimeSeconds() >= TimeOfLastMove + MoveDelay && bIsMovingRight == true)
    {
        AlienLocation = GetActorLocation();
        AlienLocation.X += -20.0f;
        SetActorLocation(AlienLocation, false);
        
        TimeOfLastMove = GetWorld()->GetTimeSeconds();
    }
}

void AAlien::AliensDance()
{
    if(GetWorld()->GetTimeSeconds() >= TimeOfLastDance + DanceDelay)
    {
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
        
        TimeOfLastDance = GetWorld()->GetTimeSeconds();
    }
}

void AAlien::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit)
{
    
    FName HitActor = HitComponent->GetFName();
    
    UE_LOG(LogTemp, Warning, TEXT("Hitting %s"), HitActor)
    
    if(HitActor == FName("InstancedBug"))
    {
    StaticBugComponent->RemoveInstance(Hit.Item); //Gets the index of the hit item in the array and removes it.
    //TODO Reverse direction on hit.
    }
    else if(HitActor == FName("Barrier3"))
    {
        AlienLocation = GetActorLocation();
        AlienLocation.Z -= 10.0f;
        SetActorLocation(AlienLocation, false);
        bIsMovingRight = false;
    }
}









